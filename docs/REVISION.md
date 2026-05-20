# Checklist de limpieza del repositorio

Lista de tareas para dejar el repositorio limpio y ordenado. No es código del
proyecto: bórrala una vez completada. Marca cada casilla a medida que avances.

> Los comandos `git rm --cached` **no borran tus archivos locales**: solo dejan
> de sincronizarlos con GitHub. Tras ejecutarlos hay que confirmar con un commit.
> Aplica cada bloque en la rama indicada.

---

## 1. Sacar del repositorio las dependencias sin modificar

Estas carpetas son `git clone` sin parches; salen del control de versiones y se
recuperan con `vcstool` (ver `dependencies.repos`).

### Rama `main`

- [ ] Quitar del seguimiento las dependencias no modificadas:

```bash
git checkout main
git rm -r --cached src/webots_ros2 src/vision_opencv src/perception_pcl src/yaets
```

### Rama `hardware-integration`

- [ ] Quitar del seguimiento las dependencias no modificadas:

```bash
git checkout hardware-integration
git rm -r --cached src/vision_opencv src/perception_pcl src/yaets
```

- [ ] Resolver el caso de `rplidar_ros`. Ahora está registrado como gitlink
      (modo `160000`) sin `.gitmodules`, por eso aparece vacío al clonar. Hay que
      quitarlo del índice:

```bash
git rm --cached src/rplidar_ros
```

> Tras estos pasos, `rplidar_ros` y el resto se descargarán con
> `vcs import src < dependencies.repos`.

---

## 2. Actualizar `.gitignore`

- [ ] Sustituir el `.gitignore` actual por la versión ampliada (incluida en este
      lote de archivos). Añade las carpetas de dependencias y los archivos de
      caché de Webots para que no vuelvan a colarse.

---

## 3. Añadir los archivos de documentación

- [ ] Copiar a la raíz: `README.md` (cada rama tiene el suyo), `LICENSE`,
      `dependencies.repos`.
- [ ] Crear la carpeta `docs/` con: `ARCHITECTURE.md`, `INSTALLATION.md`,
      `BRANCHES.md`, `THIRD_PARTY.md`.
- [ ] En la rama `hardware-integration` falta toda la documentación (no tiene ni
      README). Hay que añadirla también ahí.

---

## 4. Convertir `CLAUDE.md` en documentación real

- [ ] `CLAUDE.md` es un archivo de instrucciones para un asistente de IA. Su
      contenido técnico es bueno y ya está reaprovechado en `docs/ARCHITECTURE.md`.
      Eliminar `CLAUDE.md` del repositorio:

```bash
git rm CLAUDE.md
```

---

## 5. Limpiar archivos basura versionados

- [ ] Quitar los archivos de caché de Webots (miniaturas y proyecto temporal):

```bash
git rm --cached src/diablo_test/worlds/.diablo_robot.jpg \
                src/diablo_test/worlds/.diablo_robot.wbproj
```

- [ ] Revisar la textura con nombre-hash
      `src/diablo_test/textures/0a6c950e073a74d2e5cfa0c785a44257.jpg`. En la rama
      `hardware-integration` ya está eliminada; comprobar si se usa en el mundo
      Webots de `main` y, si no, eliminarla también ahí.

- [ ] Decidir qué hacer con `src/diablo_test/src/bridges/navmap_bridge.py`. Solo
      aparece referenciado en un bloque comentado del `CMakeLists.txt`: o se
      integra de verdad o se elimina como código muerto.

---

## 6. Rellenar metadatos del paquete

- [ ] Editar `src/diablo_test/package.xml` y rellenar los campos con marcador
      `TODO`:
  - `<description>` — descripción real del paquete.
  - `<license>` — licencia elegida (coherente con el archivo `LICENSE`).
  - `<maintainer email="...">` — correo real en lugar de `adri@todo.todo`.
- [ ] Subir el `<version>` de `0.0.0` a algo significativo (p. ej. `1.0.0`).

---

## 7. Eliminar rutas absolutas personales

- [ ] Buscar rutas codificadas a `/home/adri/` por todo el repositorio:

```bash
grep -rn "/home/adri" --include="*.md" --include="*.py" \
                      --include="*.txt" --include="*.xml" .
```

- [ ] Sustituirlas por rutas relativas, variables de entorno o, en CMake, por
      `${CMAKE_CURRENT_SOURCE_DIR}`. Esto afecta sobre todo a `CLAUDE.md` (que se
      elimina) y posiblemente a algún `CMakeLists.txt` parcheado de NavMap.

---

## 8. Mejoras opcionales del código propio

No son errores, pero elevan la calidad del repositorio de cara a quien lo herede:

- [ ] Convertir `WHEEL_RADIUS` y `TRACK_WIDTH` (codificadas en
      `diablo_driver.cpp` / `diablo_bridge.cpp`) en parámetros ROS 2, para poder
      ajustarlas sin recompilar.
- [ ] Instalar los *bridges* de Python de forma idiomática: el bloque
      `install(PROGRAMS ...)` del `CMakeLists.txt` de `diablo_test` está
      comentado. Lo limpio es instalarlos como ejecutables en
      `lib/${PROJECT_NAME}` en lugar de lanzarlos con `ExecuteProcess` apuntando
      a `share/`.

---

## 9. Verificación final

- [ ] Clon limpio de prueba: `git clone` en un directorio nuevo +
      `vcs import src < dependencies.repos` + `colcon build`. Confirmar que el
      sistema compila partiendo solo de lo que hay en GitHub.
- [ ] Repetir la prueba para la rama `hardware-integration`.
- [ ] Comprobar que `git status` está limpio y que ninguna carpeta de
      dependencias vuelve a aparecer como "untracked" o "modified".

---

> **Nota sobre el historial.** Estos pasos limpian el repositorio de aquí en
> adelante, pero los archivos grandes (p. ej. `webots_ros2`) seguirán existiendo
> en commits antiguos del historial de git. Se ha decidido **dejar el historial
> tal cual**: limpiarlo requeriría reescribirlo con `git filter-repo`, algo
> innecesario para este proyecto.
