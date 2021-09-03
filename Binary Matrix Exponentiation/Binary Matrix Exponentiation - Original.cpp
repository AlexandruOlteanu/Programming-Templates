/*
    Template created by Alexandru Olteanu
*/

vector<vector<long long> > mul(vector<vector<long long> > a, vector<vector<long long> > b)
{
	vector<vector<long long> > res;
	res = a;
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res.size(); j++)
		{
			res[i][j] = 0;
		}
	}
	for (int k = 0; k < res.size(); k++)
	{
		for (int i = 0; i < res.size(); i++)
		{
			for (int j = 0; j < res.size(); j++)
			{
				res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % bs;
			}
		}
	}
	return res;
}
 
vector<vector<long long> > matrxi_power(vector<vector<long long> > a, long long b)
{
	if (b == 1)
		return a;
	if (b == 0)
	{
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = 0; j < a.size(); j++)
			{
				a[i][j] = (i == j);
			}
		}
		return a;
	}
 
	if (b % 2)
		return mul(a, matrix_power(a, b - 1));
	return matrix_power(mul(a,a), b / 2);
}