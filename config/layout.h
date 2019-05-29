/* layout(s) */
static const float mfact       = 0.55; /* factor of master area size [0.05..0.95] */
static const int   nmaster     = 1;    /* number of clients in master area */
static const int   resizehints = 0;    /* 1 means respect size hints in tiled resizals */


static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[☰]",      tile                   },    /* first entry is default */
    { "[=]",      bstack                 },
    { "[#]",      gaplessgrid            },
    { "[𤋮]",     horizgrid              },
	{ "[^]",      NULL                   },    /* no layout function means floating behavior */

    // { "[恵]",     centeredmaster         },
	// { "[◳]",      spiral                 },
	// { "[⚪]",      monocle                },
	{ NULL,       NULL                   },    /* no layout function means floating behavior */
};

#define TILE            0
#define BOTTOMSTACK     1
#define GAPLESSGRID     2
#define HORIZONTALGRID  3
#define FLOATING        4
