
#ifndef _CONF_H_
#define _CONF_H_

#include <time.h>
#include "main.h"


extern const char *kadnode_version_str;

void conf_init( void );
void conf_load_args( int argc, char **argv );
void conf_load_file( const char filename[] );
void conf_check( void );
void conf_info( void );
void conf_reload( void );
void conf_free( void );

// value to announce
struct value {
	struct value *next;
	uint8_t value_id[SHA1_BIN_LENGTH];
	uint16_t port;
};

struct gconf_t {

	// Current time
	time_t time_now;

	// Drop privileges to user
	char *user;

	// Top level domain used by KadNode (e.g. ".p2p")
	char *query_tld;

	// Write a pid file if set
	char *pidfile;

	// Import/Export peers from this file
	char *peerfile;

	// Path to configuration file
	char *configfile;

	// Start in Foreground / Background
	int is_daemon;

	// Thread terminator
	int is_running;

	// Quiet / Verbose / Debug
	int verbosity;

	// Write log to /var/log/message
	int use_syslog;

	// Net mode (AF_INET / AF_INET6 / AF_UNSPEC)
	int af;

	// DHT port number
	char* dht_port;

	// DHT interface
	char *dht_ifname;

	// KadNode startup time
	time_t startup_time;

#ifdef __CYGWIN__
	// Start as windows service
	int service_start;
#endif

#ifdef FWD
	// Disable port forwarding
	int fwd_disable;
#endif

#ifdef LPD
	// Disable ping on multicast address
	int lpd_disable;
#endif

#ifdef CMD
	char *cmd_port;
	int cmd_disable_stdin;
#endif

#ifdef DNS
	char *dns_port;
	int dns_proxy_enable;
	char *dns_proxy_server;
#endif

#ifdef NSS
	char *nss_port;
#endif

#ifdef PTHREAD
	// DHT thread stuff
	pthread_t dht_thread;
	pthread_mutex_t dht_mutex;
#endif
};

extern struct gconf_t *gconf;

#endif // _CONF_H_
