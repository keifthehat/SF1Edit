			if(wParam &	MK_LBUTTON){
				GetCursorPos(&p);
				ScreenToClient(hWnd,&p);
				p.y-=40;
				if(p.x>=50&&p.x<=306&&p.y>=100&&p.y<=420){
					select[mode]=(p.x-50)/32+8*((p.y-100)/32);
				}
				if(p.x>=420&&p.x<=740&&p.y>=100&&p.y<=420){
					i=select[mode];
					for(x=0;x<size;x++){
						for(y=0;y<size;y++){
							j=(p.x+20*x-420)/160+2*((p.y+20*y-100)/20)+1;
							k=(p.x+20*x-420)/20;
							k%=8;
							k=7-k;
							l=Font[i][j]/pow(2.0,k);
							l%=2;
							if(!l&&j<32&&Pencil)Font[i][j]+=pow(2.0,k);
							if(l&&j<32&&!Pencil)Font[i][j]-=pow(2.0,k);
						}
					}
				}
				InvalidateRect(hWnd,NULL,0);
			}