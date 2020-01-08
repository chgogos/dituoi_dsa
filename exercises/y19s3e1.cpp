#include <iostream>
#include <list>
#include <vector>
#include <ctime>

using namespace std;

string zeros = "00000000000000000000"; // maximum 20 zeros

struct block
{
    size_t id;
    string timestamp;
    string data;
    size_t nonce;
    size_t previous_hash;
};

size_t hash_combined(const block &a_block)
{
    string c = to_string(a_block.id) + a_block.timestamp +
               a_block.data + to_string(a_block.nonce) + to_string(a_block.previous_hash);
    hash<string> h;
    return h(c);
}

void print_block(const block a_block)
{
    cout << "id:" << a_block.id;
    cout << " ts:" << a_block.timestamp;
    cout << " data:" << a_block.data;
    cout << " nonce:" << a_block.nonce;
    cout << " previous hash:" << a_block.previous_hash;
    cout << " hash:" << hash_combined(a_block) << endl;
}

void find_nonce(block &a_block, int difficulty)
{
    size_t hv = hash_combined(a_block);
    while (true)
    {
        string hvs = to_string(hv);
        if (hvs.compare(hvs.size() - difficulty, difficulty, zeros, 0, difficulty) == 0)
            break;
        a_block.nonce++;
        hv = hash_combined(a_block);
    }
}

bool check_valid_blockchain(list<block> &chain)
{
    list<block>::iterator itr = chain.begin();
    block prev = *itr;
    itr++;
    while (itr != chain.end())
    {
        if (itr->previous_hash != hash_combined(prev))
        {
            cerr << "Invalid blockchain" << endl;
            return false;
        }
        prev = *itr;
        itr++;
    }
    cerr << "Valid blockchain" << endl;
    return true;
}

int main()
{
    list<block> blockchain;
    int difficulty = 7;

    vector<string> texts = {"Alice pays 10 euros to Bob",
                            "Bob pays 5 euros to Carl",
                            "Carl pays 10 euros to David",
                            "David pays 2 euros to Alice",
                            "Alice pays 2 euros to Bob",
                            "Bob pays 5 euros to David",
                            "Carl pays 5 euros to Alice"};
    time_t now = time(0);
    tm *timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, 80, "%F %T", timeinfo);

    block genesis_block = {0, buffer, "GENESIS block", 0, 0};
    find_nonce(genesis_block, difficulty);

    blockchain.push_back(genesis_block);
    print_block(genesis_block);

    block previous_block = genesis_block;
    for (int i = 0; i < texts.size(); i++)
    {
        block a_block;
        a_block.id = i + 1;
        now = time(0);
        timeinfo = localtime(&now);
        strftime(buffer, 80, "%F %T", timeinfo);
        a_block.timestamp = buffer;
        a_block.data = texts[i];
        a_block.nonce = 0;
        a_block.previous_hash = hash_combined(previous_block);
        find_nonce(a_block, difficulty);
        blockchain.push_back(a_block);
        previous_block = a_block;
        print_block(a_block);
    }
    check_valid_blockchain(blockchain);

    list<block>::reverse_iterator ritr = blockchain.rbegin();
    ritr++;
    ritr->data = "Bob pays 5000 euros to David";
    for (block &a_block : blockchain)
    {
        print_block(a_block);
    }
    check_valid_blockchain(blockchain);
}
