#include <iostream>
#include <vector>
#include <string>
using namespace std;

int strStr(const char *source, const char *target)
{
	if (source == NULL || target == NULL)
		return -1;
	if (*source == '\0' && *target == '\0')
		return 0;
	if (*target == '\0')
		return 0;
	int lensour = strlen(source);
	int lentar = strlen(target);

	int i = 0;
	int j = 0;
	while (source[i] != '\0')
	{
		while (j<lentar && i<lensour)
		{
			if (source[i] == target[j])
			{
				i++;
				j++;
			}
			else
			{
				if (j != 0)
					i--;
				i++;
				j = 0;
			}
		}
		if(j==lentar)
			return (i - j);
	}
	return -1;
}


//int strStr(const char *source, const char *target) {
//	// write your code here
//	if (source == NULL || target == NULL)
//		return -1;
//	if (target[0] == '\0')
//		return 0;
//	int start = 0;
//	while (source[start] != '\0') {
//		int t = 0;
//		int s = 0;
//		while (source[start + s] != '\0' && target[t] != '\0' && source[start + s] == target[t]) {
//			s++;
//			t++;
//		}
//		if (target[t] == '\0')
//			return start;
//		start++;
//	}
//	return -1;
//}

int main()
{
	char target[] = { "bc" };
	char source[] = { "abcdabcdefg" };
	cout << strStr(source, target) << endl;
	system("pause");
}




/*--------------------�ܽ�--------------------*/
//		�򵥵���Ŀ����˾Ҳ�ῼ������
//		�Լ����Ľ�������ã������޸���5�β�ͨ����
//		ԭ�����������࣬����û����ó���˼·��������д������� ����->Debug->����->Debug->����...

//		�Ժ�Ӧ��ȫ���������������û�г����˼·��Ҫ���׶��ʣ�����ֻ���ǡ���첹�������߽�����


//		�Լ��ķ���Ψһ���ŵ����ڵ�target��sourceǰ���в����ظ�ʱ��
//		��������������ʱ�α�ȥ�жϣ���Ҫ���ص��ظ�������ǰ�ˡ�
//		�Լ������������α�һֱȥ�жϣ�ֻ��Ҫ���ص����¿�ʼ�ĵط����ٱȽ���j-1�Σ����������Ҫ�Լ����������