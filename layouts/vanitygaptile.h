void
tile(Monitor *m)
{
	unsigned int
		i, // Counter for loop. Use to tell whether to draw master or slave area.
		n, // Number of clients.
		h,
		r,
		oe = enablegaps, // Outer gaps enabled.
		ie = enablegaps, // Inner gaps enabled.

		mw, // Master area width.
		my, // Master y position.
		ty; //

	Client *c; // Client.

	for (n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++); // Count clients.
	if (n == 0)
		return;

	if (smartgaps == n) {
		oe = 0; // outer gaps disabled
	}

	if (n > m->nmaster) // if n > nmaster then master width = (if number nmaster > 0 then (window width + innergap) * master factor else 0)
		mw = m->nmaster ? (m->ww + m->gappiv*ie) * m->mfact : 0;
	else
		mw = m->ww - 2*m->gappov*oe + m->gappiv*ie; // else, width = width + innergap.

	// Check current client is not null each loop.
	for (i = 0, my = ty = m->gappoh*oe, c = nexttiled(m->clients); c; c = nexttiled(c->next), i++){
		if (i < m->nmaster) {
			// Draw master area.
			r = MIN(n, m->nmaster) - i;
			h = (m->wh - my - m->gappoh*oe - m->gappih*ie * (r - 1)) / r;
			resize(c, m->wx + m->gappov*oe, m->wy + my, mw - (2*c->bw) - m->gappiv*ie, h - (2*c->bw), 0);
			my += HEIGHT(c) + m->gappih*ie;

		} else {
			// Draw slave area.
			r = n - i;
			h = (m->wh - ty - m->gappoh*oe - m->gappih*ie * (r - 1)) / r;
			resize(c, m->wx + mw + m->gappov*oe, m->wy + ty, m->ww - mw - (2*c->bw) - 2*m->gappov*oe, h - (2*c->bw), 0);
			ty += HEIGHT(c) + m->gappih*ie;
		}
	}
}
