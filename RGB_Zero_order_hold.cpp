BYTE* Digital_ZOOM_RGB_2(BYTE* Buffer, int N, int M, int channel)
{
	int newN = 2 * N + 1;
	int newM = 2 * M + 1;
	BYTE*** newbuf = new BYTE **[channel];
	BYTE* resbuf = new BYTE[newM * newN * channel];
	for (int i = 0; i < channel; i++)
	{
		newbuf[i] = new BYTE * [newM];
		for (int j = 0; j < newM; j++)
		{
			newbuf[i][j] = new BYTE[newN];
		}
	}
	int  row,col, cur;
	col = 0;
	row = 0;
	for (int i = 0; i < newM; i++)
	{
		for (int j = 0; j < newN; j++)
		{
			for (int k = 0; k < channel; k++)
			{
				newbuf[k][i][j] = 0;
			}
		}
	}
	//doldurma
	for (int i = 0; i < newM; i++)
	{
		for (int j = 0; j < newN; j++)
		{
			for (int k = 0; k < channel; k++)
			{
				if (i % 2 == 1 & j % 2 == 1)
				{
					newbuf[k][i][j] = Buffer[channel*(row*N+col) + k];
				}
			}
			if(j%2 == 1)
				col++;
		}
		col = 0;
		if (i % 2 == 1)
			row++;
	}//elemanlarý koyma

	for (int i = 0; i < newM; i++)
	{
		for (int j = 0; j < newN; j++)
		{
			for (int k = 0; k < channel; k++)
			{
				cur = i * newN + j;
				resbuf[channel * cur + k] = newbuf[k][i][j];
			}
		}
	}//3D to 1D transform
	return resbuf;

}
