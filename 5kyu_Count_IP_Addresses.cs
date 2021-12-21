//https://www.codewars.com/kata/526989a41034285187000de4/csharp

public class CountIPAddresses
{
    public static long IpsBetween(string start, string end)
    {
        long ret = 0;

        string[] f1 = start.Split('.');
        string[] f2 = end.Split('.');

        long step = 256 * 256 * 256;
        for (int i = 0; i < 4; ++i)
        {
            long i1 = long.Parse(f1[i]);
            long i2 = long.Parse(f2[i]);

            long d = i2 - i1;

            ret += d * step;
            step /= 256;
        }

        return ret;
    }
}
