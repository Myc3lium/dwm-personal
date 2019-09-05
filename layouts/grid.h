void
grid(Monitor *m) {
    // Gapped grid layout.
	unsigned int
		// oe = enablegaps, // Outer gaps.
		// ie = enablegaps, // Inner gaps.
		i, // Loop counter. Drawing master/slave area.
		n,
		cx, // Client x position.
		cy, // Client y position.
		cw, // Client width.
		ch, // Client heigh.
		aw,
		ah,
		cols, // Number of columns.
		rows; // Number of rows.

	Client *c;

	for(n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next))
		n++;

	/* grid dimensions */
	for(rows = 0; rows <= n/2; rows++)
		if(rows*rows >= n)
			break;
	cols = (rows && (rows - 1) * rows >= n) ? rows - 1 : rows;

	/* window geoms (cell height/width) */
	if (enablegaps){
		// Divide into columns.
		ch = m->wh / (rows ? rows : 1);
		cw = m->ww / (cols ? cols : 1);

		// Subtract gap widths.
		ch -= (rows ? rows + 1 : 1) * gappih; // Gaps that run side to side  (=).
		cw -= (cols ? cols + 1 : 1) * gappiv; // Gaps that run top to bottom (|).

	} else {
		ch = m->wh / (rows ? rows : 1);
		cw = m->ww / (cols ? cols : 1);
	}

	for(i = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next)) {
		cx = m->wx + (i / rows) * cw;
		cy = m->wy + (i % rows) * ch;

		/* adjust height/width of last row/column's windows */
		ah = ((i + 1)    % rows == 0) ? m -> wh - ch * rows : 0;
		aw = (i >= rows * (cols - 1)) ? m -> ww - cw * cols : 0;

		resize(c,
				cx,
				cy,
				cw - 2 * c->bw + aw,
				ch - 2 * c->bw + ah,
				False);
		i++;
	}
}

// void
// grid(Monitor *m) {
// 	unsigned int i, n, cx, cy, cw, ch, aw, ah, cols, rows;
// 	Client *c;
//
// 	for(n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next))
// 		n++;
//
// 	/* grid dimensions */
// 	for(rows = 0; rows <= n/2; rows++)
// 		if(rows*rows >= n)
// 			break;
// 	cols = (rows && (rows - 1) * rows >= n) ? rows - 1 : rows;
//
// 	/* window geoms (cell height/width) */
// 	ch = m->wh / (rows ? rows : 1);
// 	cw = m->ww / (cols ? cols : 1);
// 	for(i = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next)) {
// 		cx = m->wx + (i / rows) * cw;
// 		cy = m->wy + (i % rows) * ch;
// 		/* adjust height/width of last row/column's windows */
// 		ah = ((i + 1) % rows == 0) ? m->wh - ch * rows : 0;
// 		aw = (i >= rows * (cols - 1)) ? m->ww - cw * cols : 0;
// 		resize(c, cx, cy, cw - 2 * c->bw + aw, ch - 2 * c->bw + ah, False);
// 		i++;
// 	}
// }
