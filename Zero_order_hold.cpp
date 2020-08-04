BYTE** Digital_ZOOM_2(BYTE* Buffer, int N, int M)
{
	BYTE** newbuf = new BYTE * [2 * M + 1];
	int row, col;
	row = 0;
	col = 0;
	for (int i = 0; i < 2 * M + 1; i++)
	{
		newbuf[i] = new BYTE[2 * N + 1];
	}
	for (int i = 0; i < 2 * M + 1; i++)
	{
		for (int j = 0; j < 2 * N + 1; j++)
		{
			newbuf[i][j] = 0;
		}
	}
	//
	for (int i = 0; i < 2 * M + 1; i++)
	{
		for (int j = 0; j < 2 * N + 1; j++)
		{
			if (i % 2 == 1 & j % 2 == 1)
			{
				newbuf[i][j] = Buffer[row*N+col];
				col++;
			}
		}
		col = 0;
		if (i % 2 == 1)
			row++;
	}
	return newbuf;
}
