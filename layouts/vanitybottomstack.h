// static void
// bstack(Monitor *m) {
// 	int mwidth,
// 		mheight,
//
// 		swidth,
// 		sheight,
// 		sxpos,
// 		sypos;
//
// 	unsigned int i, n;
// 	Client *c;
//
// 	for (n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++);
// 	if (n == 0)
// 		return;
//
// 	if (n > m->nmaster) {
// 		mheight = m->nmaster ? m->mfact * m->wh : 0;
// 		mwidth  = m->ww / (m->nmaster);
// 		mwidth -= (n - m->nmaster + 1) * gaps;
// 		mwidth -= (n - m->nmaster) * (c -> bw);
//
// 		swidth  = m->ww / (n - m->nmaster);
// 		swidth -= (n - m->nmaster + 1) * gaps;
// 		swidth -= (n - m->nmaster) * (2 * c -> bw);
//
// 		sypos = m->wy + mheight;
//
// 	} else {
// 		// Only drawing master area.
// 		mheight = m -> wh;
// 		swidth  = m -> ww;
//
// 		sypos   = m -> wy;
//
// 		mheight  = m -> wh;
// 		mheight -= (2 * gaps);
// 		mheight -= (2 * c -> bw);
// 	}
//
// 	for (i = mx = 0, sx = m->wx, c = nexttiled(m->clients); c; c = nexttiled(c->next), i++) {
// 		if (i < m->nmaster) {
// 			// Draw master windows.
// 			w = (m->ww - mx) / (MIN(n, m->nmaster) - i);
// 			resize(c,
// 					m->wx + mx + (gaps),
// 					m->wy + (gaps),
// 					w  - (2 * c->bw) - (2*gaps),
// 					mh - (2 * c->bw) - (2*gaps),
// 					0);
//
// 			mx += WIDTH(c) + (gaps);
//
// 		} else {
// 			// Draw slave windows.
// 			h = m->wh - mh - (gaps);
// 			resize(c,
// 					sx + (gaps),
// 					sy,
// 					sw - (2 * c->bw) - (2*gaps),
// 					h  - (2 * c->bw),
// 					0);
//
// 			if (sw != m->ww)
// 			    sx += WIDTH(c) + (gaps);
// 		}
// 	}
// }

static void
bstack (Monitor *m){
	int mwidth,
		mheight,
		mxp,
		myp,

		swidth,
		sheight,
		sxp,
		syp,

		gaps = (enablegaps * gappih) // Outer gaps enabled.
		;

	unsigned int i, n;
	Client *c;

	for (n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++);
	if (n == 0)
		return;

	if (n > m->nmaster){ // Dividing screen into master/slave.
		// mwidth  = (m->ww / (m->nmaster)) - (gaps *(m->nmaster+1));
		mwidth  = (m->ww - (gaps * (m->nmaster + 1))) / m->nmaster;
		mheight = (m->wh * m->mfact) - (gaps);
		mxp     = m->wx + (gaps);
		myp     = m->wy + (gaps);

		sheight = m->wh - (m->wh * m->mfact) - (gaps*2);

		swidth  = (m->ww - (gaps *((n - m->nmaster) + 1))) / (n - m->nmaster);
		sxp     = (m->wx + (gaps));
		syp     = myp + mheight + (gaps);


	} else { // Only drawing master area.
		mwidth  = (m->ww - (gaps * (n + 1))) / n;
		mheight = m -> wh - (2 * gaps);
		mxp     = m->wx + (gaps);
		myp     = m->wy + (gaps);

		sheight= swidth= sxp= syp= 0;
	}

	for (i = 0, c = nexttiled(m->clients); i < n && c; c = nexttiled(c->next), i++){
		if (i < m->nmaster){
			resize(c,
					mxp,
					myp,
					mwidth  - (2*c->bw),
					mheight - (2*c->bw),
            0);

			mxp += (mwidth) + (gaps);

		} else {
			resize(c,
					sxp,
					syp,
					swidth  - (2*c->bw),
					sheight - (2*c->bw),
            0);
			sxp += (swidth) + (gaps);

		}
	}
}

// static void
// bstack(Monitor *m) {
// 	int w,
// 		h,
//
// 		mh,
// 		mx,
//
// 		sx,
// 		gaps = (enablegaps * gappih), // Outer gaps enabled.
// 		sy,
// 		sw;
//
// 	unsigned int i, n;
// 	Client *c;
//
// 	for (n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++);
// 	if (n == 0)
// 		return;
//
// 	if (n > m->nmaster) {
// 		mh = m->nmaster ? m->mfact * m->wh : 0;
// 		sw = m->ww / (n - m->nmaster);
// 		sy = m->wy + mh;
//
// 	} else {
// 		// Only drawing master area.
// 		mh = m->wh;
// 		sw = m->ww;
// 		sy = m->wy;
// 	}
//
// 	for (i = mx = 0, sx = m->wx, c = nexttiled(m->clients); c; c = nexttiled(c->next), i++) {
// 		if (i < m->nmaster) {
// 			// Draw master windows.
// 			w = (m->ww - mx) / (MIN(n, m->nmaster) - i);
// 			resize(c,
// 					m->wx + mx + (gaps),
// 					m->wy + (gaps),
// 					w  - (2 * c->bw) - (2*gaps),
// 					mh - (2 * c->bw) - (2*gaps),
// 					0);
//
// 			mx += WIDTH(c) + (gaps);
//
// 		} else {
// 			// Draw slave windows.
// 			h = m->wh - mh - (gaps);
// 			resize(c,
// 					sx + (gaps),
// 					sy,
// 					sw - (2 * c->bw) - (2*gaps),
// 					h  - (2 * c->bw),
// 					0);
//
// 			if (sw != m->ww)
// 			    sx += WIDTH(c) + (gaps);
// 		}
// 	}
// }
