void
gaplessgrid(Monitor *m) {
	unsigned int
		n,     // Number of clients.

		cols,  // Number of columns.
		rows,  // Number of rows.

		cn,    // Column number.
		rn,    // Row number.

		i,     // Counter for current client.

		cx,    // Client x position.
		cy,    // Client y position.

		cw,    // Client width.
		ch;    // Client height.

	const unsigned int gaps = (enablegaps ? gappiv : 0);

	Client *c;

	for(n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++) ;
	if(n == 0)
		return;

	/* grid dimensions */
	for(cols = 0; cols <= n/2; cols++)
		if(cols*cols >= n)
			break;
	if(n == 5) /* set layout against the general calculation: not 1:2:2, but 2:3 */
		cols = 2;
	rows = n/cols;

	/* window geometries */
	// cw = cols ? m->ww / cols : m->ww;
	// cw -= (cols + 1) * gappiv; // Gaps that run top to bottom (|).
	cw = (m->ww - (cols+1) *gaps) / (cols ? cols : 1);

	cn = 0; /* current column number */
	rn = 0; /* current row number */

	for(i = 0, c = nexttiled(m->clients); c; i++, c = nexttiled(c->next)) {
		if(i/rows + 1 > cols - n%cols)
			rows = n/cols + 1;

		ch = (m-> wh - (rows + 1) *gaps) / (rows ? rows: 1);

		cx = m->wx +
			(cn == 0 ? gaps :
			  (cn * cw) + ((cn + 1) * gaps));
		      // number of previously drawn column widths + (nth drawing column width * vertical gap).

		cy = m->wy +
			(rn == 0 ? gaps :
			  (rn * ch) + ((rn + 1) * gaps));
		      // number of previously drawn row heights + (nth drawing row height * vertical gap).


		// cx = m->wx + cn * cw + gappiv;
		// cy = m->wy + rn * ch + gappih;

		resize(c, cx, cy, cw - 2 * c->bw, ch - 2 * c->bw, False);
		rn++;
		if(rn >= rows) {
			rn = 0;
			cn++;
		}
	}
}
