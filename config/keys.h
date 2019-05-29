#include <X11/XF86keysym.h>

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

static Key keys[] = {
	/* modifier                     key        function        argument */

	// ~~~~ Run commands ~~~~
	{ MODKEY,                       XK_b,      spawn,          { .v = dmenucmd   }},
	{ MODKEY|ShiftMask,             XK_i,      spawn,          { .v = menuScript }},
	{ MODKEY,                       XK_u,      spawn,          { .v = termcmd    }},
	{ MODKEY|ShiftMask,             XK_u,      spawn,          { .v = tabtermcmd    }},

	// ~~~~ Media Keys ~~~~
	{ 0,                            XF86XK_AudioRaiseVolume, spawn, { .v = volumeInc  }},
	{ 0,                            XF86XK_AudioLowerVolume, spawn, { .v = volumeDec  }},
	{ 0,                            XF86XK_AudioMute,        spawn, { .v = volumeMute }},
	{ 0,                            XF86XK_AudioPlay,        spawn, { .v = cmusPause  }},
	{ 0,                            XF86XK_AudioNext,        spawn, { .v = cmusNext   }},
	{ 0,                            XF86XK_AudioPrev,        spawn, { .v = cmusPrev   }},

	// ~~~~ Movement and focus keys ~~~~
	{ 0,                       XK_F11,    togglebar,      { 0 }},
	{ MODKEY,                  XK_j,      focusstack,     { .i = +1 }},
	{ MODKEY,                  XK_k,      focusstack,     { .i = -1 }},
	{ MODKEY|ShiftMask,        XK_j,      rotatestack,    { .i = +1 }},
	{ MODKEY|ShiftMask,        XK_k,      rotatestack,    { .i = -1 }},
	{ MODKEY|ShiftMask,	       XK_comma,  cyclelayout,    { .i = -1 }},
	{ MODKEY|ShiftMask,        XK_period, cyclelayout,    { .i = +1 }},

	{ MODKEY,                  XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                  XK_period, focusmon,       {.i = +1 } },

	{ MODKEY,                  XK_h,      setmfact,       { .f = -0.05 }},
	{ MODKEY,                  XK_l,      setmfact,       { .f = +0.05 }},
	{ MODKEY,                  XK_Return, zoom,           { 0 }},
	{ MODKEY,                  XK_Tab,    view,           { 0 }},
	{ MODKEY,                  XK_q,      killclient,     { 0 }},


	{ MODKEY,                  XK_bracketright,      incnmaster,  { .i = +1 }},
    { MODKEY,                  XK_bracketleft,       incnmaster,  { .i = -1 }},

	// ~~~~ Layout change keys ~~~~
	{ MODKEY,            XK_t, setlayout, { .v = &layouts [TILE]           }},
	{ MODKEY|ShiftMask,  XK_t, setlayout, { .v = &layouts [BOTTOMSTACK]    }},
	{ MODKEY,            XK_g, setlayout, { .v = &layouts [GAPLESSGRID]    }},
	{ MODKEY|ShiftMask,  XK_g, setlayout, { .v = &layouts [HORIZONTALGRID] }},
	{ MODKEY,            XK_f, setlayout, { .v = &layouts [FLOATING]       }},

	// { MODKEY,            XK_m, setlayout, { .v = &layouts[3] }}, // 3 centeredfloatingmaster
	// { MODKEY,            XK_s, setlayout, { .v = &layouts[4] }}, // 4 spiral
	// { MODKEY,            XK_n, setlayout, { .v = &layouts[5] }}, // 5 grid
	// { MODKEY|ShiftMask,  XK_m, setlayout, { .v = &layouts[6] }}, // 6 monocle

	// ~~~~ Tag keys ~~~~
	{ MODKEY,                       XK_1,      view,           { .ui = ~0 }},
	{ MODKEY|ShiftMask,             XK_1,      tag,            { .ui = ~0 }},

	TAGKEYS(                        XK_7,                      0)
	TAGKEYS(                        XK_8,                      1)
	TAGKEYS(                        XK_9,                      2)
	TAGKEYS(                        XK_0,                      3)
	TAGKEYS(                        XK_minus,                  4)

	// ~~~~ Miscellaneous ~~~~
	{ MODKEY|ShiftMask,             XK_q,      quit,           { 0 }},
	{ MODKEY|ShiftMask,             XK_r,      spawn,          { .v = restart    }},
	{ MODKEY|ControlMask,           XK_l,      spawn,          { .v = lockScreen }}
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      { 0 }},
	{ ClkLtSymbol,          0,              Button3,        setlayout,      { .v = &layouts[2] }},
	{ ClkWinTitle,          0,              Button2,        zoom,           { 0 }},
	{ ClkStatusText,        0,              Button2,        spawn,          { .v = termcmd }},
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      { 0 }},
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, { 0 }},
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    { 0 }},
	{ ClkTagBar,            0,              Button1,        view,           { 0 }},
	{ ClkTagBar,            0,              Button3,        toggleview,     { 0 }},
	{ ClkTagBar,            MODKEY,         Button1,        tag,            { 0 }},
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      { 0 }},
};
