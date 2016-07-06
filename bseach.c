/**
 как это работает: (алгоритм в общем)
 луший поиск -  поиск в сбалансированном древе поиска.
 особенность сбалансированного дерева в том, что и слева и справа одинаковое кол-во элементов и с одной стороны все элементы точно меньше чем с другой
 раз нам дан отсортированный массив, то глупо смотреть каждый элемент, будет n сравнений, когда в дереве их будет log2(n).
 делать дерево ради одноразового поиска не стоит приложенных усилий, потому искать вхождение будем подобным алгоритмом основанным на половинном делении.
 
 рекурсивная функция принимает на вход 5 параметров:
 1 - сам массив, 2 и 3 - границы в которых следует работать (обычно 0 и n)
 4 - число, относительно которого мы будем сравнивать элементы массива
 5 - просто n - кол-во элементов в массиве
 
 Если в массиве нет элементов больше чем X, то программа вернет n (в граничных случаях будут возращены a или (b-1). )
 */
int bsearch(int *az,int a,int b,int x,int n)
{
    if ((b-a)>1)
    {
        int c=(a+b)/2;
        if (az[c]>x)
        {
            return bsearc(az, a, c, x, n);
        }
        else
        {
            return bsearc(az, c, b, x, n);
        }
    }
    else
    {
        int c=(a+b)/2;
        if (az[n-1]<=x)
        {
            return n;
        }
        while (az[c]<=x)
        {
            c++;
        }
        return c;
    }
}
