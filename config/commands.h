/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
#define HOME "/home/myc3lium"
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]   = { "perl",   HOME"/.bin/i3dmd",  NULL };
static const char *menuScript[] = { "bash", HOME"/i3/menuScript", NULL };
static const char *termcmd[]    = { "urxvt",                      NULL };
static const char *tabtermcmd[] = { "tabd", "-name", "terminal", "urxvt", "-embed", NULL };

// ~~~~ Media Control Keys ~~~~
static const char *volumeInc[]  = { "pactl", "set-sink-volume", "0", "+10%", NULL };
static const char *volumeDec[]  = { "pactl", "set-sink-volume", "0", "-10%", NULL };
static const char *volumeMute[] = { "pactl", "set-sink-volume", "0", "0%",   NULL };
static const char *cmusPause[]  = { "cmus-remote", "--pause", NULL };
static const char *cmusNext[]   = { "cmus-remote", "--next",  NULL };
static const char *cmusPrev[]   = { "cmus-remote", "--prev",  NULL };

// ~~~~ Util ~~~~
static const char *lockScreen[] = { "bash", HOME "/i3/lock.sh", NULL };
static const char *restart[]    = { HOME"/.bin/dwm-restart",      NULL };
