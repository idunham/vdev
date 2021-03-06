#!/bin/sh

# helper to link a char device to /dev/char/$MAJOR:$MINOR

. $VDEV_HELPERS/subr.sh

case "$VDEV_ACTION" in

   add)

      add_link ../$VDEV_PATH $VDEV_MOUNTPOINT/char/$VDEV_MAJOR:$VDEV_MINOR $VDEV_METADATA
      ;;

   remove)

      remove_links $VDEV_METADATA
      ;;

   *)
      fail 1 "Unknown action '$VDEV_ACTION'"
      ;;

esac

exit 0
