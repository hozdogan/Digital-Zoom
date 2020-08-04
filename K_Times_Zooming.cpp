BYTE** Digital_ZOOM(BYTE** Buffer, int N, int M, int zoom_xk)//geçiþler cok keskin
{
	int newDimensionN = N + (N - 1) * (zoom_xk - 1);
	int newDimensionM = M + (M - 1) * (zoom_xk - 1);
	double dif;
	int count = 0;
	BYTE** newbuf = new BYTE * [newDimensionM];
	for (int i = 0; i < newDimensionM; i++)
	{
		newbuf[i] = new BYTE[newDimensionN];
	}//nxm
	//dizi ici sýfýrlama
	for (int i = 0; i < newDimensionM; i++)
	{
		for (int j = 0; j < newDimensionN; j++)
		{
			newbuf[i][j] = 0;
		}
	}

	//satýrlarýn koyulmasý
	for (int row = 0; row < M; row++)
	{
		for (int col = 0; col < N - 1; col++)
		{
			dif = abs(Buffer[row][col] - Buffer[row][col + 1]) / zoom_xk;//int uchar sýkýntý olabilir testte bak
			dif = round(dif);
			if (Buffer[row][col] < Buffer[row][col + 1])
			{
				for (int j = col * zoom_xk; j < (col + 1) * zoom_xk; j++)
				{
					newbuf[row * zoom_xk][j] = Buffer[row][col] + count * dif;
					count++;
				}
				count = 0;
			}
			else if (Buffer[row][col] > Buffer[row][col + 1])
			{
				for (int j = col * zoom_xk; j < (col + 1) * zoom_xk; j++)
				{
					newbuf[row * zoom_xk][j] = Buffer[row][col] - count * dif;
					count++;
				}
				count = 0;
			}

		}
	}
	count = 0;
	//sutunlarýn konulmasý row col yer deðiþtirir
	for (int row = 0; row < M - 1; row++)
	{
		for (int col = 0; col < N; col++)
		{
			dif = abs(Buffer[row][col] - Buffer[row + 1][col]) / zoom_xk;//int uchar sýkýntý olabilir testte bak
			dif = round(dif);
			if (Buffer[row][col] < Buffer[row + 1][col])
			{
				for (int j = row * zoom_xk; j < (row + 1) * zoom_xk; j++)
				{
					newbuf[j][col * zoom_xk] = Buffer[row][col] + count * dif;
					count++;
				}
				count = 0;
			}
			else if (Buffer[row][col] > Buffer[row + 1][col])
			{
				for (int j = row * zoom_xk; j < (row + 1) * zoom_xk; j++)
				{
					newbuf[j][col * zoom_xk] = Buffer[row][col] - count * dif;
					count++;
				}
				count = 0;
			}

		}
	}
	return newbuf;
}
