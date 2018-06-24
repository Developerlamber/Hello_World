/*
Decsrption: 交换函数
[Param 1] [INOUT] unsigned long *array  待排序的数组 
[Param 2] [IN] unsigned long arraysize 数组长度
*/
int __Swap_TwoNumber(unsigned long *array, unsigned long i, unsigned long j)
{
	if (NULL == array)
	{
		return -1;
	}

	unsigned long ulTemp = 0;

	ulTemp = array[i];
	array[i] = array[j];
	array[j] = ulTemp;

	return 0;
}

/*
Decsrption: 选择排序函数
[Param 1] [INOUT] unsigned long *array  待排序的数组 
[Param 2] [IN] unsigned long arraysize 数组长度
*/
int __Select_Sort(unsigned long *array, unsigned long arraysize)
{
	if ((NULL == array) || (0 == arraysize))
	{
		return -1;
	}

	unsigned long ulMaxIndexTemp = 0;
	unsigned long ulTemp = 0;
    unsigned long ulSortIndex_1 = 0;
    unsigned long ulSortIndex_2 = 0;

	for (ulSortIndex_1 = 0; ulSortIndex_1 < arraysize - 1; ++ulSortIndex_1)
	{

		ulMaxIndexTemp = ulSortIndex_1;

		for(ulSortIndex_2 = ulSortIndex_1 + 1; ulSortIndex_2 < arraysize; ++ulSortIndex_2)
		{
			if (array[ulSortIndex_2] < array[ulMaxIndexTemp])
			{
				ulMaxIndexTemp = ulSortIndex_2;
			}
		}

		if (ulMaxIndexTemp != ulSortIndex_1)
		{
			ulTemp = array[ulMaxIndexTemp];
			array[ulMaxIndexTemp] = array[ulSortIndex_1];
			array[ulSortIndex_1] = ulTemp;
		}

	}

	return 0;
}

/*
Decsrption: 冒泡排序函数
[Param 1] [INOUT] unsigned long *array  待排序的数组 
[Param 2] [IN] unsigned long arraysize 数组长度
*/
int __Pop_Sort(unsigned long *array, unsigned long arraysize)
{
	if ((NULL == array) || (0 == arraysize))
	{
		return -1;
	}

	unsigned long ulSortIndex_1 = 0;
	unsigned long ulSortIndex_2 = 0;
	unsigned long ulTemp = 0;

	for (ulSortIndex_1 = 0; ulSortIndex_1 < arraysize - 1; ++ulSortIndex_1)
	{
	  	for (ulSortIndex_2 = 0; ulSortIndex_2 < arraysize - 1 - ulSortIndex_1; ++ulSortIndex_2)
	  	{
	  		if (array[ulSortIndex_2] > array[ulSortIndex_2 + 1])
	  		{
	  			ulTemp = array[ulSortIndex_2];
	  			array[ulSortIndex_2] = array[ulSortIndex_2 + 1];
	  			array[ulSortIndex_2 + 1] = ulTemp; 
	  		}
	  	}
	}

	return 0;  
}

/*
Decsrption: 鸡尾酒排序函数
[Param 1] [INOUT] unsigned long *array  待排序的数组 
[Param 2] [IN] unsigned long arraysize 数组长度
*/
int __CockTail_Sort(unsigned long *array, unsigned long arraysize)
{
	if ((NULL == array) || (0 == arraysize))
	{
		return -1;
	}

	int iRet = 0; 
	unsigned long ulLeft = 0;
	unsigned long ulRight = arraysize - 1;

	while (ulLeft < ulRight)
	{
		for(int i = ulLeft; i < ulRight; ++i)
		{
			if (array[i] > array[i + 1])
			{
				iRet = __Swap_TwoNumber(array, i, i + 1);
				if (0 != iRet)
				{
					return -1;
				}
			}
		}

		ulRight--;

		for (int i = ulRight; i > ulLeft; --i)
		{
			if (array[i - 1] > array[i])
			{
				iRet = __Swap_TwoNumber(array, i - 1, i);
				if (0 != iRet)
				{
					return -1;
				}
			}
		}

		ulLeft++;
	}

	return 0;
}