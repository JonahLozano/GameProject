#include "../include/levelLoader.h"

levelLoader::levelLoader()
{
    //ctor
    scale = 0.1f;

    rows = 0;
    cols = 0;

    spawnRows = 0;
    spawnCols = 0;
}

levelLoader::~levelLoader()
{
    //dtor
}
void levelLoader::loadCSV(const string& filename)
{
    cout << "loading level..." << endl;
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    while (getline(file, line))
    {
        rows++;
        cols = 0;
        stringstream ss(line);
        string cell;
        vector<unique_ptr<Block>> row;

        while (getline(ss, cell, ','))
        {
            cols++;
            if(cell == "air")
            {
                row.push_back(make_unique<AirBlock>());
                row.back()->blockTexture("images/air.png");
            }
            else if (cell == "boundary")
            {
                row.push_back(make_unique<BoundaryBlock>());
                row.back()->blockTexture("images/boundary.png");
            }
            else if (cell == "chest")
            {
                row.push_back(make_unique<ChestBlock>());
                row.back()->blockTexture("images/chest.png");
            }
            else if (cell == "cloud")
            {
                row.push_back(make_unique<CloudBlock>());
                row.back()->blockTexture("images/cloud.png");
            }
            else if (cell == "enemy")
                {
                row.push_back(make_unique<EnemyBlock>());
                row.back()->blockTexture("images/nycat5.png");
            }
            else if (cell == "finish")
                {
                row.push_back(make_unique<FinishBlock>());
                row.back()->blockTexture("images/finish.png");
            }
            else if (cell == "grass")
            {
                row.push_back(make_unique<GrassBlock>());
                row.back()->blockTexture("images/grass.png");
            }
            else if (cell == "spawn")
            {
                row.push_back(make_unique<SpawnBlock>());
                row.back()->blockTexture("images/alien.png");
                spawnRows = rows;
                spawnCols = cols;
            }
        }
        levelData.push_back(move(row));
    }
    file.close();
    cout << "loading complete." << endl;
    cout << "spawnRows: " << spawnRows << ", spawnCols: " << spawnCols << endl;
}

void levelLoader::drawLevel()
{
    float rowIndex = 0.0 + (rows+1)*2 - spawnRows;
    for (const auto& row : levelData)
    {
        float columnIndex = 0.0 - spawnCols;
        for (const auto& block : row)
        {
            // block->draw();
            block->placeBlock(columnIndex,rowIndex,scale/10.0f);
            block->drawBlock();
            columnIndex += 2;
        }
        rowIndex -= 2;
        // cout << endl;
    }
}
void levelLoader::setScale(float newScale)
{
    scale = newScale;
}

