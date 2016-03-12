#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/kaaninan/ProjectX/ROS/src/rosserial/rosserial_python"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/kaaninan/ProjectX/ROS/install/lib/python2.7/dist-packages:/home/kaaninan/ProjectX/ROS/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/kaaninan/ProjectX/ROS/build" \
    "/usr/bin/python" \
    "/home/kaaninan/ProjectX/ROS/src/rosserial/rosserial_python/setup.py" \
    build --build-base "/home/kaaninan/ProjectX/ROS/build/rosserial/rosserial_python" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/kaaninan/ProjectX/ROS/install" --install-scripts="/home/kaaninan/ProjectX/ROS/install/bin"
