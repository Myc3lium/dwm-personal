static void setgaps(int oh, int ov, int ih, int iv);
static void incrgaps(const Arg *arg);
static void incrigaps(const Arg *arg);
static void incrogaps(const Arg *arg);
static void incrohgaps(const Arg *arg);
static void incrovgaps(const Arg *arg);
static void incrihgaps(const Arg *arg);
static void incrivgaps(const Arg *arg);
static void togglegaps(const Arg *arg);
static void defaultgaps(const Arg *arg);
static int enablegaps = 1;

// Vanitygaps
static const unsigned int gappih    = 20;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 20;       /* vert inner gap between windows */
static const unsigned int gappoh    = 20;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 20;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */


void
setgaps(int oh, int ov, int ih, int iv)
{
	if (oh < 0) oh = 0;
	if (ov < 0) ov = 0;
	if (ih < 0) ih = 0;
	if (iv < 0) iv = 0;

	selmon->gappoh = oh;
	selmon->gappov = ov;
	selmon->gappih = ih;
	selmon->gappiv = iv;
	arrange(selmon);
}

void tile(Monitor*);
void gaplessgrid(Monitor*);
void toggleResizeHints();

void
togglegaps(const Arg *arg)
{
	if (!(selmon -> lt[selmon->sellt] -> arrange == tile || selmon -> lt[selmon->sellt] -> arrange == gaplessgrid || selmon -> lt[selmon->sellt] -> arrange == bstack || selmon -> lt[selmon->sellt] -> arrange == monocle))
		return;

	toggleResizeHints(); // Turn off resize hints when turning off gaps, so we don't get wierd gaps.
	enablegaps = !enablegaps;
	arrange(selmon);
}

void
defaultgaps(const Arg *arg)
{
	setgaps(gappoh, gappov, gappih, gappiv);
}

void
incrgaps(const Arg *arg)
{
	setgaps(
		selmon->gappoh + arg->i,
		selmon->gappov + arg->i,
		selmon->gappih + arg->i,
		selmon->gappiv + arg->i
	);
}

void
incrigaps(const Arg *arg)
{
	setgaps(
		selmon->gappoh,
		selmon->gappov,
		selmon->gappih + arg->i,
		selmon->gappiv + arg->i
	);
}

void
incrogaps(const Arg *arg)
{
	setgaps(
		selmon->gappoh + arg->i,
		selmon->gappov + arg->i,
		selmon->gappih,
		selmon->gappiv
	);
}

void
incrohgaps(const Arg *arg)
{
	setgaps(
		selmon->gappoh + arg->i,
		selmon->gappov,
		selmon->gappih,
		selmon->gappiv
	);
}

void
incrovgaps(const Arg *arg)
{
	setgaps(
		selmon->gappoh,
		selmon->gappov + arg->i,
		selmon->gappih,
		selmon->gappiv
	);
}

void
incrihgaps(const Arg *arg)
{
	setgaps(
		selmon->gappoh,
		selmon->gappov,
		selmon->gappih + arg->i,
		selmon->gappiv
	);
}

void
incrivgaps(const Arg *arg)
{
	setgaps(
		selmon->gappoh,
		selmon->gappov,
		selmon->gappih,
		selmon->gappiv + arg->i
	);
}
