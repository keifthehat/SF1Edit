GetCursorPos(&p);
ScreenToClient(hWnd, &p);
p.y -= 40;

if (wParam &	MK_LBUTTON) {
	CSGraphs[subselect[mode][0]]->move(p.x, p.y);
}