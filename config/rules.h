/* tagging */
static const char *tags[] = {
	"  ", // other.     0
	" ﴣ ", // anon.      1
	"  ", // firefox.   2
	"  ", // terminal.  3
	"  ", // media.     4
};
#define DESKTOP(N) (N > 0 ? (1 << (N - 1)) : 0)

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *
	 * class      instance                title     tag mask isfloating   monitor
	 */

	{ "Firefox",  NULL,                   NULL,     DESKTOP(3),  0,  -1 },
	{ "URxvt",    "calendar",             NULL,     DESKTOP(4),  0,  -1 },
	{ "URxvt",    "monitor",              NULL,     DESKTOP(4),  0,  -1 },
	{ "URxvt",    "workspace4-terminal",  NULL,     DESKTOP(4),  0,  -1 },
	{ "URxvt",    "music-cmus",           NULL,     DESKTOP(5),  0,  -1 },
	{ "URxvt",    "music-mpv",            NULL,     DESKTOP(5),  0,  -1 },
	{ "mpv",      "gl",                   NULL,     DESKTOP(5),  0,  -1 },
	{ "tabbed",   "tabd_manpages",        "urxvt",  DESKTOP(0),  0,  -1 },
	{ "tabbed",   "tabd_terminal",        "urxvt",  DESKTOP(0),  0,  -1 },
};
