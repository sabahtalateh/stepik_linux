FROM sabahtalateh/stepik_linux_ubuntu
RUN apt-get install man -y
RUN apt-get install ltrace -y
RUN apt-get install strace -y
RUN apt-get install gdb -y
CMD tail -f /dev/null
