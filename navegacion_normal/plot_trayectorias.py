import matplotlib.pyplot as plt
from rosbags.rosbag2 import Reader
from rosbags.typesys import Stores, get_typestore

# Configuración
BAG_PATH = '.'  # Ruta al directorio que contiene el .mcap y metadata.yaml
ODOM_TOPIC = '/odom'
PATH_TOPIC = '/mpc/path'  # Cambiar a '/planner_node/CostmapPlanner/path' si es necesario
GOAL_TOPIC = '/goal_pose'

odom_x, odom_y = [], []
path_x, path_y = [], []
goal_x, goal_y = None, None
start_x, start_y = None, None

typestore = get_typestore(Stores.ROS2_HUMBLE)

# Leer el rosbag
with Reader(BAG_PATH) as reader:
    # Filtrar las conexiones de los tópicos requeridos
    connections = [x for x in reader.connections if x.topic in [ODOM_TOPIC, PATH_TOPIC, GOAL_TOPIC]]
    
    for connection, timestamp, rawdata in reader.messages(connections=connections):
        msg = typestore.deserialize_cdr(rawdata, connection.msgtype)
        
        if connection.topic == ODOM_TOPIC:
            x = msg.pose.pose.position.x
            y = msg.pose.pose.position.y
            odom_x.append(x)
            odom_y.append(y)
            # Guardar el primer punto de odometría como inicio
            if start_x is None:
                start_x, start_y = x, y
                
        elif connection.topic == PATH_TOPIC:
            # Nos quedamos con el path que contenga más poses (generalmente el plan inicial completo),
            # evitando los paths cortos de replanificación final o el path vacío al llegar a la meta.
            if len(msg.poses) > len(path_x):
                path_x = [p.pose.position.x for p in msg.poses]
                path_y = [p.pose.position.y for p in msg.poses]
            
        elif connection.topic == GOAL_TOPIC:
            # En caso de múltiples envíos, se queda con el último objetivo
            goal_x = msg.pose.position.x
            goal_y = msg.pose.position.y

# Generación del gráfico
plt.figure(figsize=(8, 6))

# Dibujar odometría
plt.plot(odom_x, odom_y, label='Trayectoria real (/odom)', color='blue', linewidth=1.5, linestyle='-')

# Dibujar trayectoria planificada
if path_x and path_y:
    plt.plot(path_x, path_y, label='Trayectoria planificada', color='red', linewidth=1.5, linestyle='--')

# Dibujar puntos clave
if start_x is not None:
    plt.scatter([start_x], [start_y], color='green', marker='o', s=80, label='Inicio', zorder=5)
if goal_x is not None:
    plt.scatter([goal_x], [goal_y], color='purple', marker='*', s=150, label='Objetivo', zorder=5)

# Formateo
plt.xlabel('Posición X [m]')
plt.ylabel('Posición Y [m]')
plt.title('Comparativa de trayectorias (Simulación)')
plt.grid(True, linestyle=':', alpha=0.6)
plt.legend(loc='best')
plt.axis('equal') # Mantiene la proporción espacial métrica 1:1

# Exportación del archivo
plt.savefig('c1_sim_trayectorias.pdf', format='pdf', bbox_inches='tight')
print("Archivo 'c1_sim_trayectorias.pdf' generado correctamente.")