from setuptools import find_packages
from setuptools import setup

setup(
    name='motion_msgs',
    version='1.0.0',
    packages=find_packages(
        include=('motion_msgs', 'motion_msgs.*')),
)
