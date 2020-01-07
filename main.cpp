#include "./src/cpluspark.h"

int main()
{
    cs::Parser p;
    cs::DataFrame df = p.readCVS("./task2.csv").splitBy(',').withDefaultHeaders().createDF();

    // dataframe iterator
    for(auto row: df.dfIterator()){
        std::cerr << row[0] << ",";
        std::cerr << row[1] << ",";
        std::cerr << row[2] << std::endl;
    }

    // dataframe iterator
    for(auto row: df.dfIterator()){
        std::cerr << row["userID"] << ",";
        std::cerr << row["A"] << ",";
        std::cerr << row["B"] << std::endl;
    }

    df.show(10);
    df.sortBy<std::string>("A", '<');
    df.show(10);

    df.sortBy<std::string>("A", '>');
    df.show(10);
    
    df.sortBy<int>("A", '<');
    df.show(10);

    df.sortBy<float>("A", '<');
    df.show(10);
    
    df.sortBy<double>("A", '<');
    df.show(10);

    df.sortBy<long>("A", '<');
    df.show(10);

    df.sortBy<int>("B", '<');
    df.show(10);

    int max = df.getMax<int>("B");
    std::cerr << max << std::endl;

    df.addCol("C");
    df.show(10);

    for(auto& row: df.dfIterator()){
        int a = std::stoi(row["A"]);
        int b = std::stoi(row["B"]);

        row["C"] = std::to_string(a-b);
    }

    df.show(10);

    float avg = df.getAvg<float>("C");
    std::cerr << avg << std::endl;

    cs::DataFrame test1_df = p.readCVS("./123.txt").splitBy(',').withDefaultHeaders().createDF();
    std::cerr << test1_df.getRowSize() << std::endl;;
    test1_df.show(1);

    cs::DataFrame test2_df = p.readCVS("./123.txt").splitBy(',').withHeaders({"A","B","C"}).createDF();
    std::cerr << test2_df.getRowSize() << std::endl;;
    test2_df.show(2);

    // db::DataFrame new_df = df.select("A");
    // new_df.show(10);

    return 0;
}