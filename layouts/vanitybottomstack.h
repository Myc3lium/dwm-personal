static void
bstack(Monitor *m) {
	int w, h, mh, mx, tx, ty, tw;
	unsigned int i, n;
	Client *client;

	for (n = 0, client = nexttiled(m->clients); client; client = nexttiled(client->next), n++);
	if (n == 0)
		return;
	if (n > m->nmaster) {
		mh = m->nmaster ? m->mfact * m->wh : 0;
		tw = m->ww / (n - m->nmaster);
		ty = m->wy + mh;
	} else {
		mh = m->wh;
		tw = m->ww;
		ty = m->wy;
	}
	for (i = mx = 0, tx = m->wx, client = nexttiled(m->clients); client; client = nexttiled(client->next), i++) {
		if (i < m->nmaster) {
			w = (m->ww - mx) / (MIN(n, m->nmaster) - i);
			resize(client, m->wx + mx, m->wy, w - (2 * client->bw), mh - (2 * client->bw), 0);
			mx += WIDTH(client);
		} else {
			h = m->wh - mh;
			resize(client, tx, ty, tw - (2 * client->bw), h - (2 * client->bw), 0);
			if (tw != m->ww)
				tx += WIDTH(client);
		}
	}
}
