void
tile(Monitor *m)
{
	unsigned int i, n, h, r, oe = enablegaps, ie = enablegaps, mw, my, ty;
	Client *c;

	for (n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++);
	if (n == 0)
		return;

	if (smartgaps == n) {
		oe = 0; // outer gaps disabled
	}

	if (n > m->nmaster)
		mw = m->nmaster ? (m->ww + m->gappiv*ie) * m->mfact : 0;
	else
		mw = m->ww - 2*m->gappov*oe + m->gappiv*ie;
	for (i = 0, my = ty = m->gappoh*oe, c = nexttiled(m->clients); c; c = nexttiled(c->next), i++)
		if (i < m->nmaster) {
			r = MIN(n, m->nmaster) - i;
			h = (m->wh - my - m->gappoh*oe - m->gappih*ie * (r - 1)) / r;
			resize(c, m->wx + m->gappov*oe, m->wy + my, mw - (2*c->bw) - m->gappiv*ie, h - (2*c->bw), 0);
			my += HEIGHT(c) + m->gappih*ie;
		} else {
			r = n - i;
			h = (m->wh - ty - m->gappoh*oe - m->gappih*ie * (r - 1)) / r;
			resize(c, m->wx + mw + m->gappov*oe, m->wy + ty, m->ww - mw - (2*c->bw) - 2*m->gappov*oe, h - (2*c->bw), 0);
			ty += HEIGHT(c) + m->gappih*ie;
		}
}
