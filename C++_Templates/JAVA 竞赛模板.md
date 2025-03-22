
### Input
```java
static BufferedReader bf=new BufferedReader(new InputStreamReader(System.in));
public static void main(String[] args){
    // 字符、整数、字符串读入
    char c=buffer.readLine().charAt(0);
    int n=Integer.parseInt(bf.readLine());
    String s=bf.readLine();
    // 字符串数组
    String[] arr=bf.readLine().split(" ");
    // 整数数组，空格分割，未给出容量，回车结束
    int[] intArr=Array.stream(bf.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    // 整数数组，回车分割，给出容量
    int n=10;
    int[] intArr=new int[n];
    for(int i=0;i<n;i++) intArr[i]=Integer.parseInt(bf.readLine());
    // 整数数组，回车分割，未给出容量，* 结束（可替换）
    List<Integer> intList=new ArrayList<>();
    while(true){
        String temp=bf.readLine().split(" ");
        if(temp[0].equals("*")) break;
        for(String s:temp) intList.add(Integer.parseInt(s));
    }
    // 二维整数数组，给出 n
    int n=10;
    int[][] twoDimArr=new int[n][n];
    for(int i=0;i<n;i++){
        String[] temp=bf.readLine().split(" ");
        for(int j=0;j<n,j++) twoDimArr[i][j]=Integer.parseInt(temp[j]);
    }
    // 连续读入整数，已知 n
    String[] str=bf.readLine().split(" ");
    int a=Integer.parseInt(str[0]);
    int b=Integer.parseInt(str[1]);
}
```
### BigInteger
```java
import java.math.*;
public static void main(String[] args){
    // 新建大数
    BigInteger bi1=new BigInteger("6798454586764535787634789643567");
    BigInteger bi2=BigInteger.valueOf(1234567890L);
    // 基本大数运算
    BigInteger sum=bi1.add(bi2);
    BigInteger difference=bi1.substract(bi2);
    BigInteger product=bi1.multiply(bi2);
    BigInteger quotient=bi1.divide(bi2);
    BigInteger remainder=bi1.remainder(bi2);
    // 比较运算
    int compareResult=bi1.compareTo(bi2); // 返回 -1, 0, 1
    boolean isEqual=bi1.equals(bi2);
    // 类型转换
    long longValue=bi1.longValue();
    String stringValue=bi1.toString();
    // 便捷运算
    BigInteger absValue=bi1.abs();
    BigInteger power=bi1.pow(3);
    BigInteger shiftedLeft=bi1.shiftLeft(2); // 左移指定位数
    BigInteger shiftedRight=bi1.shiftRight(2); // 右移指定位数
    /* 还有很多，考试看 API 得了 */
}
```
### Output
```java
static PrintWriter pw=new PrintWriter(new OutputStreamWriter(System.out));
pw.println(xxx);
```
