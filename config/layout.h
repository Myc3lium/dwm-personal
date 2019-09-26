/* layout(s) */
static const float mfact       = 0.55; /* factor of master area size [0.05..0.95] */
static const int   nmaster     = 1;    /* number of clients in master area */
static int         resizehints = 1;    /* 1 means respect size hints in tiled resizals */

void
toggleResizeHints (){
    resizehints = !resizehints;
}

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[+]",     gaplessgrid            },
    { "[≡]",     bstack                 },
    { "[]=",     tile                   }, // First entry is default.
    { "(º)",      NULL                   }, // No layout function means floating behavior.
    { "[Ω]",     monocle                },
    { NULL,     NULL                   }, // No layout function means floating behavior.
};

#define GAPLESSGRID    0
#define BOTTOMSTACK    1
#define TILE           2
#define FLOATING       3
#define MONOCLE        4
