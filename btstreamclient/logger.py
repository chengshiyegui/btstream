# -*- coding: utf8 -*-
#
# Copyright (C) 2012 Gabriel Mendonça
#
# This file is part of BTStream.
# BTStream is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# BTStream is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with BTStream.  If not, see <http://www.gnu.org/licenses/>.
#
#
#  Created on: 24/01/2012
#      Author: gabriel
#

from time import time

log_file = None

LOG_FILE_NAME = "%d.log" % time()

def log(message):
    print "%d: %s" % (time(), message)

def log_event(message):
    print "%d: [Event] %s" % (time(), message)

def log_error(error, debug):
    print "%d: [Error] %s" % (time(), error)
    print "[Debug] ", debug


def log_to_file(message):
    global log_file, LOG_FILE_NAME

    if log_file is None:
        log_file = open(LOG_FILE_NAME, "w")

    log_file.write(message)

def close():
    global log_file

    if log_file is not None:
        log_file.close()



