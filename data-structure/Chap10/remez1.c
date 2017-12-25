void Remez(double a, double b, double p[7], double (*f)(double))
/*
a ˫����ʵ�ͱ�����������˵�ֵ b ˫����ʵ�ͱ����������Ҷ˵�ֵ
p˫����ʵ��һά���飬����Ϊ7������5�����һ�±ƽ�����ʽ��6��ϵ�������һ��Ϊ����ʽ��ƫ��(��һ��Ϊ����ֵ)
f ˫����ʵ�ͺ���ָ�������ָ����㺯��f(x)ֵ�ĺ�����
*/
{
    int i, j, k, m, kk;//i,j��ά��������У�kһά����Ԫ�غţ�m��ֵ�����
    double h = 0.00001 * (b - a);
    double x1, newx, s, t;
    double x[7], ff[7], X[7][7], temp[7][7], tempf[7];
    double (*xx)[7] = X;//���X����ָ�����ʽ���Է�������ÿ�ε����еĲ�����һ�еĲ���
    for (k = 0; k < 7; k++) {
        t = cos((6 - k) * PI / 6);
        x[k] = (b + a + (b - a) * t) / 2.0;
        ff[k] = (*f)(x[i]);
    }          //��������ȡn+1���б�ѩ�����ʽ�Ľ��������Ϊ��ʼ�㼯
    double pre_mu = 1.0e35; //��֤�����ܹ�����
    double mu = 1.0;
    for (i = 0; i < 7; i++) {
        ff[i] = (*f)(x[i]);

        xx[i][0] = 1.0;
        for (j = 1; j < 6; j++)
            xx[i][j] = x[i] * xx[i][j - 1];
        xx[i][6] = mu;
        mu = -mu;
    }         //��ʼX������
//���濪ʼ����
    int flagx;������//��¼f(newx)-P(newx)�ķ���
    int times = 0; //��¼��������
    while (times < 100) {
        for (i = 0; i < 7; i++) {
            tempf[i] = ff[i];
            for (j = 0; j < 7; j++)
                temp[i][j] = xx[i][j];
        }
        Gauss_sort_all(temp, tempf, p, NULL);

        mu = fabs(p[6]);
        if (fabs(mu - pre_mu) < REPS)
            return;//���㾫��Ҫ�󣬷���
        pre_mu = mu;  //δ���㾫��Ҫ�󣬼�¼�´˴ε�\mu,Ȼ��ʼ���������
        //ɨ��Ѱ�����ƫ���newx
        x1 = a;
        newx = a;   //newx��¼���ҵ������ƫ���
        while (x1 < b) {
            s = (*f)(x1);
            t = p[5];
            for (i = 4; i >= 0; i--)
                t = t * x1 + p[i];

            if (fabs(s - t) > mu) {
                flagx = (s - t) > 0 ? 1 : -1;
                mu = fabs(s - t);
                newx = x1;
            }
            x1 = x1 + h;
        }
        //ɨ��Ѱ�����ƫ���Ӧ����λ��m
        for (i = 0; i < 7; i++)
            if (newx > x[i]) m = i;
        //������滻��ͬʱ����ϵ������xx�ʹ�ź���ֵ�Ľ������ff
        if (newx < x[0]) {
            kk = 0;    //��¼�´��޸ĵ��к�
            s = (*f)(x[0]);
            t = p[5];
            for (i = 4; i >= 0; i--)
                t = t * x[0] + p[i];
            s = s - t;
            if (s * flagx < 0.0) //��ţ���ӵ���ǰ
            {
                for (k = 5; k >= 0; k--) {
                    ff[k + 1] = ff[k];
                    x[k + 1] = x[k];
                }
                double *tempxx = xx[6];
                for (i = 6; i > 0; i--)
                    xx[i] = xx[i - 1];
                xx[0] = tempxx;
            }
        } else if (newx > x[6]) {
            kk = 6;   //��¼�´��޸ĵ��к�
            s = (*f)(x[6]);
            t = p[5];
            for (i = 4; i >= 0; i--)
                t = t * x[6] + p[i];
            s = s - t;
            if (s * flagx < 0.0) //��ţ���ӵ����
            {
                for (k = 0; k < 6; k++) {
                    ff[k] = ff[k + 1];
                    x[k] = x[k + 1];
                }

                double *tempxx = xx[0];
                for (i = 0; i < 6; i++)
                    xx[i] = xx[i + 1];
                xx[6] = tempxx;
            }
        } else //���ֵ��x[m]��x[m+1]֮��
        {
            s = (*f)(x[m]);
            t = p[5];
            for (i = 4; i >= 0; i--)
                t = t * x[m] + p[i];
            s = s - t;
            if (s * flagx > 0.0) //ͬ�ţ����滻x[m]
            {
                kk = m;       //��¼�´��޸ĵ��к�
                xx[kk][6] = -xx[kk + 1][6];
            } else           //��ţ����滻x[m+1]
            {
                kk = m + 1;     //��¼�´��޸ĵ��к�
                xx[kk][6] = -xx[m][6];
            }
        }
        x[kk] = newx;
        ff[kk] = (*f)(x[kk]);
        for (j = 1; j < 6; j++)
            xx[kk][j] = x[kk] * xx[kk][j - 1];
        times++;
    }
}
