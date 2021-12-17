//https://www.codewars.com/kata/540d0fdd3b6532e5c3000b5b

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp4
{
    public class KataSolution
    {
        public class itemT
        {
            public string variable { get; set; }
            public int order { get; set; }
            public long coeff { get; set; }
        }

        static List<itemT> calc(List<itemT> lhs, List<itemT> rhs)
        {
            Dictionary<int, List<itemT>> dic = new Dictionary<int, List<itemT>>();

            for (int i = 0; i < lhs.Count; ++i)
            {
                for (int j = 0; j < rhs.Count; ++j)
                {
                    itemT i0 = lhs[i];
                    itemT i1 = rhs[j];

                    itemT newItem = new itemT { coeff = i0.coeff * i1.coeff, order = i0.order + i1.order };
                    if (i0.variable != null)
                        newItem.variable = i0.variable;
                    else if (i1.variable != null)
                        newItem.variable = i1.variable;

                    if (dic.ContainsKey(newItem.order) == false)
                        dic.Add(newItem.order, new List<itemT>());

                    dic[newItem.order].Add(newItem);
                }
            }

            List<itemT> ret = new List<itemT>();

            foreach (var item in dic)
            {
                if (item.Value.Count == 0)
                    continue;

                if (item.Value.Count > 1)
                {
                    for (int i = 1; i < item.Value.Count; ++i)
                    {
                        item.Value[0].coeff += item.Value[i].coeff;
                    }
                }

                ret.Add(item.Value[0]);
            }

            return ret;
        }

        private static List<itemT> convert(string str)
        {
            List<itemT> ret = new List<itemT>();

            str = str.Substring(1, str.Length - 2);

            string sub = null;
            for (int i = 0; i < str.Length; ++i)
            {
                if (str[i] == '+' || str[i] == '-')
                    sub += str[i];
                else
                {
                    int n = 0;
                    if (int.TryParse(str[i].ToString(), out n))
                        sub += str[i];
                    else
                    {
                        itemT it = new itemT { variable = str[i].ToString(), order = 1 };

                        if (sub == null)
                            it.coeff = 1;
                        else if (sub == "-")
                            it.coeff = -1;
                        else
                            it.coeff = int.Parse(sub);

                        if (it.coeff != 0)
                            ret.Add(it);

                        sub = null;
                    }
                }
            }

            if (sub != null)
            {
                itemT it = new itemT { coeff = int.Parse(sub), variable = null, order = 0 };
                if (it.coeff != 0)
                    ret.Add(it);
            }

            return ret;
        }

        public static string Expand(string expr)
        {
            Console.WriteLine(expr);

            string[] fields = expr.Split('^');
            string itemStr = fields[0];
            int p = int.Parse(fields[1]);

            if (p == 0)
                return "1";

            var aas = convert(itemStr);

            List<itemT> start = aas;
            for (int i = 1; i < p; ++i)
            {
                start = calc(start, aas);
            }

            string ret = null;
            foreach (var item in start)
            {
                if (item.variable != null)
                {
                    if (item.order == 1)
                        ret += string.Format("{0}{1}{2}", item.coeff > 0 ? "+" : "", item.coeff == 1 ? "" : item.coeff == -1 ? "-" : item.coeff.ToString(), item.variable);
                    else
                        ret += string.Format("{0}{1}{2}^{3}", item.coeff > 0 ? "+" : "", item.coeff == 1 ? "" : item.coeff == -1 ? "-" : item.coeff.ToString(), item.variable, item.order);
                }
                else
                    ret += string.Format("{0}{1}", item.coeff > 0 ? "+" : "", item.coeff);
            }

            if (ret[0] == '+')
                ret = ret.Substring(1, ret.Length - 1);

            return ret;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            string val = KataSolution.Expand("(y-5)^15");
        }
    }
}
