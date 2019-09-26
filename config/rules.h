/* tagging */
static const char *tags[] = {
	" ", // other.      0
	" ", // anon.       1
	" ", // firefox.    2
	" ", // terminal.   3
	" ", // media.      4

	"",   // scratchpad. 5
	"",   // monitor.    6
	"",   // calendar.   7
};

#define DESKTOP(N) .tags = (N > 0 ? (1 << (N - 1)) : 0)
#define ALL        .tags = 0

#define ISFLOATING  .isfloating = 1
#define TILING      .isfloating = 0
#define ISCENTER    .iscentered = 1
#define ISSTICKY    .issticky   = 1

#define SCRATCHPAD  3


static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *
	 * class      instance                title     tag mask isfloating   monitor
	 */

	{ "Tor Browser", NULL,                  NULL,    DESKTOP(2), ISFLOATING, ISCENTER, -1 },
	{ "Firefox",     NULL,                  NULL,    DESKTOP(3), TILING,     .iscentered=0, -1 },
	//{ "URxvt",       "workspace4-terminal", NULL,    DESKTOP(4), TILING,     .iscentered=0, -1 },
	//{ "URxvt",       "music-cmus",          NULL,    DESKTOP(5), TILING,     .iscentered=0, -1 },
	//{ "URxvt",       "music-mpv",           NULL,    DESKTOP(5), TILING,     .iscentered=0, -1 },

	{ "xterm-256color",       "workspace4-terminal", NULL,    DESKTOP(4), TILING,     .iscentered=0, -1 },
	{ "xterm-256color",       "music-cmus",          NULL,    DESKTOP(5), TILING,     .iscentered=0, -1 },
	{ "xterm-256color",       "music-mpv",           NULL,    DESKTOP(5), TILING,     .iscentered=0, -1 },
	{ "mpv",         NULL,                  NULL,    DESKTOP(5), TILING,     .iscentered=0, -1 },
	//{ "tabbed",      "tabd_manpages",       "urxvt", ALL,        TILING,     .iscentered=0, -1 },
	//{ "tabbed",      "tabd_terminal",       "urxvt", ALL,        TILING,     .iscentered=0, -1 },

	{ "tabbed",      "tabd_manpages",       "st", ALL,        TILING,     .iscentered=0, -1 },
	{ "tabbed",      "tabd_terminal",       "st", ALL,        TILING,     .iscentered=0, -1 },

    //{ "URxvt",       "scratchpad",          NULL,    DESKTOP(6), ISFLOATING,  ISCENTER,     -1 },
	//{ "URxvt",       "monitor",             NULL,    DESKTOP(7), ISFLOATING, .iscentered=0, -1 },
	//{ "URxvt",       "calendar",            NULL,    DESKTOP(8), ISFLOATING, .iscentered=0, -1 },

    { "xterm-256color",       "scratchpad",          NULL,    DESKTOP(6), ISFLOATING,  ISCENTER,     -1 },
	{ "xterm-256color",       "monitor",             NULL,    DESKTOP(7), ISFLOATING, .iscentered=0, -1 },
	{ "xterm-256color",       "calendar",            NULL,    DESKTOP(8), ISFLOATING, .iscentered=0, -1 },
};
