if (!ScriptsLoaded&&strlen(file)) {
	if (p.x >= 50 && p.x <= 176 && p.y >= 30 && p.y <= 52) {
		LoadDialog(file);
		LoadBE(file);
		LoadBExit(file);
	}
}

if (ScriptsLoaded) {
	if (p.x >= 76 && p.x <= 145 && p.y >= 10 && p.y <= 25) {
		focus = 1;
	}

	if (p.x >= 55 && p.x <= 75 && p.y >= 8 && p.y <= 28) {
		u = subselect[mode][0];
		subselect[mode][0]--;
		if (subselect[mode][0] < 0)subselect[mode][0] = NUM_BE - 1;
		BEGraphs[subselect[mode][0]]->w = BEGraphs[u]->w;
		BEGraphs[subselect[mode][0]]->h = BEGraphs[u]->h;
		BEGraphs[subselect[mode][0]]->buildList();
		//BEGraphs[subselect[mode][0]]->vx = 0;
		//BEGraphs[subselect[mode][0]]->vy = 0;
	}

	if (p.x >= 146 && p.x <= 166 && p.y >= 8 && p.y <= 28) {
		u = subselect[mode][0];
		subselect[mode][0]++;
		if (subselect[mode][0] > NUM_BE - 1)subselect[mode][0] = 0;
		BEGraphs[subselect[mode][0]]->w = BEGraphs[u]->w;
		BEGraphs[subselect[mode][0]]->h = BEGraphs[u]->h;
		BEGraphs[subselect[mode][0]]->buildList();
		//BEGraphs[subselect[mode][0]]->vx = 0;
		//BEGraphs[subselect[mode][0]]->vy = 0;
	}

	BEGraphs[subselect[mode][0]]->click(p.x, p.y);
}