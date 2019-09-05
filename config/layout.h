/* layout(s) */
static const float mfact       = 0.55; /* factor of master area size [0.05..0.95] */
static const int   nmaster     = 1;    /* number of clients in master area */
static int         resizehints = 0;    /* 1 means respect size hints in tiled resizals */

void
toggleResizeHints (){
    resizehints = !resizehints;
}

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "全",     bstack                 },
    { "",     tile                   }, // First entry is default.
    { "﩯",     gaplessgrid            },
    { "",      NULL                   }, // No layout function means floating behavior.
    { "恵",     monocle                },
    { NULL,     NULL                   }, // No layout function means floating behavior.
};

#define BOTTOMSTACK    0
#define TILE           1
#define GAPLESSGRID    2
#define FLOATING       3
#define MONOCLE        4
