# Cpluspark
Local simple "small" data framework without setting fucking anything. For
- csv

now.

## Free Syntax
You can create dataframe by
```
DataFrame df = p.readCVS("yourfile.csv").withDefaultHeaders().splitBy(',').createDF();
```
or
```
DataFrame df = p.readCVS("yourfile.csv").splitBy(',').withDefaultHeaders().createDF();
```

## Example
- [show](https://github.com/jysh1214/cpluspark/tree/master/example/01_show)
- [sort](https://github.com/jysh1214/cpluspark/tree/master/example/02_sort)
- [max & min & avg ...](https://github.com/jysh1214/cpluspark/tree/master/example/03_getMax_getMin)
- [add col](https://github.com/jysh1214/cpluspark/tree/master/example/04_addCol)
- [remove col](https://github.com/jysh1214/cpluspark/tree/master/example/05_removeCol)
- [select col](https://github.com/jysh1214/cpluspark/tree/master/example/06_selectCol)
- [customize headers](https://github.com/jysh1214/cpluspark/tree/master/example/07_withHeaders)
