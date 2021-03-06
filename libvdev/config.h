/*
   vdev: a virtual device manager for *nix
   Copyright (C) 2015  Jude Nelson

   This program is dual-licensed: you can redistribute it and/or modify
   it under the terms of the GNU General Public License version 3 or later as 
   published by the Free Software Foundation. For the terms of this 
   license, see LICENSE.LGPLv3+ or <http://www.gnu.org/licenses/>.

   You are free to use this program under the terms of the GNU General
   Public License, but WITHOUT ANY WARRANTY; without even the implied 
   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
   See the GNU General Public License for more details.

   Alternatively, you are free to use this program under the terms of the 
   Internet Software Consortium License, but WITHOUT ANY WARRANTY; without
   even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
   For the terms of this license, see LICENSE.ISC or 
   <http://www.isc.org/downloads/software-support-policy/isc-license/>.
*/

#ifndef _VDEV_CONFIG_H_
#define _VDEV_CONFIG_H_

#include "util.h"
#include "param.h"

#include <getopt.h>

#define VDEV_CONFIG_NAME        "vdev-config"
#define VDEV_OS_CONFIG_NAME     "vdev-OS"

#define VDEV_CONFIG_FIRMWARE_DIR  "firmware"
#define VDEV_CONFIG_PSTAT         "proc_check"
#define VDEV_CONFIG_ACLS          "acls"
#define VDEV_CONFIG_ACTIONS       "actions"
#define VDEV_CONFIG_HELPERS       "helpers"
#define VDEV_CONFIG_DEFAULT_MODE  "default_permissions"
#define VDEV_CONFIG_DEFAULT_POLICY "default_policy"     // allow or deny
#define VDEV_CONFIG_PIDFILE_PATH  "pidfile"
#define VDEV_CONFIG_LOGFILE_PATH  "logfile"
#define VDEV_CONFIG_DEBUG_LEVEL   "debuglevel"
#define VDEV_CONFIG_MOUNTPOINT    "mountpoint"
#define VDEV_CONFIG_ONCE          "run_once"
#define VDEV_CONFIG_FOREGROUND    "foreground"

// structure for both file configuration and command-line options
struct vdev_config {
   
   // config file path (used by opts)
   char* config_path;
   
   // firmware directory 
   char* firmware_dir;
   
   // ACLs directory 
   char* acls_dir;
   
   // actions directory 
   char* acts_dir;
   
   // helpers directory 
   char* helpers_dir;
   
   // default policy (0 for deny, 1 for allow)
   int default_policy;
   
   // debug level
   int debug_level;
   
   // PID file path 
   char* pidfile_path;
   
   // logfile path (set to "syslog" to send directly to syslog)
   char* logfile_path;
   
   // path to where /dev lives 
   char* mountpoint;
   
   // run once to populate /dev
   bool once;
   
   // run in the foreground 
   bool foreground;
   
   // OS-specific configuration (for keys under "OS")
   vdev_params* os_config;
   
   // default permission bits for mknod 
   mode_t default_mode;
};

C_LINKAGE_BEGIN

int vdev_config_init( struct vdev_config* conf );
int vdev_config_load( char const* path, struct vdev_config* conf );
int vdev_config_load_file( FILE* file, struct vdev_config* conf );
int vdev_config_free( struct vdev_config* conf );

int vdev_config_usage( char const* progname );
int vdev_config_load_from_args( struct vdev_config* config, int argc, char** argv, int* fuse_argc, char** fuse_argv );
int vdev_config_fullpaths( struct vdev_config* config );

C_LINKAGE_END

#endif