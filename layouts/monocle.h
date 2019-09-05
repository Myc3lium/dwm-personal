void
monocle(Monitor *m)
{
	unsigned int n = 0;
	Client *c;
	int gaps = (enablegaps * m->gappih); // Outer gaps enabled.

	for (c = m->clients; c; c = c->next)
		if (ISVISIBLE(c))
			n++;

	if (n > 0) /* override layout symbol */
		snprintf(m->ltsymbol, sizeof m->ltsymbol, "[%d]", n);

	for (c = nexttiled(m->clients); c; c = nexttiled(c->next))
		// resize(c, m->wx, m->wy, m->ww - 2 * c->bw, m->wh - 2 * c->bw, 0);
		resize(c,
				m->wx + gaps,
				m->wy + gaps,
				m->ww - (2*c->bw) - (2*gaps),//m->gappiv*ie,
				m->wh  - (2*c->bw) - (2*gaps),
				0);
}
