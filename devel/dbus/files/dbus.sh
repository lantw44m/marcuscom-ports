#!/bin/sh
#
# $FreeBSD$
#
# PROVIDE: dbus
# REQUIRE: DAEMON
# KEYWORD: FreeBSD
#
# Add the following lines to /etc/rc.conf to enable the D-BUS messaging system:
#
# dbus_enable="YES"
#

dbus_enable="NO"
dbus_flags="--system"

. %%RC_SUBR%%

name=dbus
rcvar=`set_rcvar`

command="%%PREFIX%%/bin/dbus-daemon-1"
pidfile="/var/run/${name}.pid"

load_rc_config ${name}
run_rc_command "$1"
