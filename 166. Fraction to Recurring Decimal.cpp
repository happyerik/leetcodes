string fractionToDecimal(int numerator, int denominator)
{
	string str = "";
	if (numerator == 0)
		return "0";

	long long n = static_cast<long long>(numerator);
	long long d = static_cast<long long>(denominator);
	string pre_fix = "";

	if ((n < 0 && d > 0) || (n > 0 && d < 0))
		pre_fix = "-";

	n = abs(n);
	d = abs(d);

	if (n < d)
		str = "0.";
	else
	{
		long long tmp_val = n / d;
		while (tmp_val > 0)
		{
			str.push_back(tmp_val % 10 + '0');
			tmp_val /= 10;
		}
		reverse(str.begin(), str.end());
		n %= d;
		if (n == 0)
			return pre_fix + str;
		str.push_back('.');
	}

	string left = "";
	long long tmp1 = n, tmp2;
	map<pair<long long, long long>, int> mi;
	int i = 0;
	while (1)
	{
		tmp2 = (tmp1 * 10) / d;
		tmp1 = (tmp1 * 10) % d;
		left.push_back(tmp2 + '0');
		if (tmp1 == 0)
			break;

		if (mi.find(make_pair(tmp1, tmp2)) == mi.end())
			mi.insert(make_pair(make_pair(tmp1, tmp2), i));
		else
			break;
		i++;
	}

	//extra operations
	if (tmp1 != 0)
	{
		left.insert(left.begin() + mi[make_pair(tmp1, tmp2)], '(');
		left[left.size() - 1] = ')';
	}

	return pre_fix + str + left;
}