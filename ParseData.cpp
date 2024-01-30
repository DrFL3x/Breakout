#include "ParseData.h"

LevelData ParseData::parseLevel(const std::string& filename)
{
    LevelData leveldata;
    
    // Load the XML file
    std::ifstream file(filename);
    std::vector<char> buffer((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    buffer.push_back('\0');


    // Parse XML
    rapidxml::xml_document<> doc;
    doc.parse<0>(&buffer[0]);

    // root node
    rapidxml::xml_node<>* levelNode = doc.first_node("Level");

    //  Level node att
    leveldata.rowCount = levelNode->first_attribute("RowCount")->value();
    leveldata.columnCount = levelNode->first_attribute("ColumnCount")->value();
    leveldata.rowSpacing = levelNode->first_attribute("RowSpacing")->value();
    leveldata.columnSpacing = levelNode->first_attribute("ColumnSpacing")->value();
    leveldata.backgroundTexture= levelNode->first_attribute("BackgroundTexture")->value();
    

    // child nodes 
    rapidxml::xml_node<>* brickTypes = levelNode->first_node("BrickTypes");
    rapidxml::xml_node<>* bricksNode = levelNode->first_node("Bricks");


    rapidxml::xml_node<>* brickTypeNode;

    // BrickType nodes
    for ( brickTypeNode = brickTypes->first_node("BrickType"); brickTypeNode; brickTypeNode = brickTypeNode->next_sibling()) 
    {
        //Bricktpe node att

        BrickData brickdata;

        brickdata.Id = brickTypeNode->first_attribute("Id")->value();
        brickdata.Texture   = brickTypeNode->first_attribute("Texture")->value();
        brickdata.HitPoints = brickTypeNode->first_attribute("HitPoints")->value();
        brickdata.HitPoints = brickTypeNode->first_attribute("HitSound")->value();
        brickdata.BreakSound= brickTypeNode->first_attribute("BreakSound")->value();
        brickdata.BreakScore= brickTypeNode->first_attribute("BreakScore")->value();    
    }

    rapidxml::xml_node<>* brickNode;
    // individual Bricks nodes

    for (brickNode = bricksNode->first_node(); brickNode; brickNode = brickNode->next_sibling()) 
    {
        // Access text content of each Bricks node
        std::string bricksText = brickNode->value();
    }

    return leveldata;
}




