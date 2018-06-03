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


		ulTemp = array[ulMaxIndexTemp];
		array[ulMaxIndexTemp] = array[ulSortIndex_1];
		array[ulSortIndex_1] = ulTemp;
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

}