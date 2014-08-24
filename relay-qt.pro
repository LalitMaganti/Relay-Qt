TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS = relay \
          test

test.depends = relay
