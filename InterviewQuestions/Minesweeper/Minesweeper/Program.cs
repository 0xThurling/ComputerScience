using System.Data;

Console.WriteLine("Choose your width: ");
int width = Convert.ToInt16(Console.ReadLine());
Console.WriteLine("Choose your height: ");
int height = Convert.ToInt16(Console.ReadLine());

char[,] board = new char[height,width];
char[,] guess = new char[height,width];
PopulateBoard(board);

PrintBoardTest();
Console.WriteLine();

Console.WriteLine("Choose your row: ");
int row = Convert.ToInt16(Console.ReadLine());
Console.WriteLine("Choose your col: ");
int column = Convert.ToInt16(Console.ReadLine());

start(row, column);

void start(int row, int col)
{
    int mineCount = checkCellsAround(row, col);

    if (mineCount == 0)
    {
        CheckColumns(row, col);
    }
    else
    {
        board[row, col] = Convert.ToChar(mineCount.ToString());
    }
}

void CheckColumns(int row, int col)
{
    int posCol = col;
    int negCol = col;
    int count;

    do
    {
        count = checkCellsAround(row, negCol);
        if(TryGetValue(row, negCol, out char value))
        {
            if (value != '-')
            {
                break;
            }
            board[row, negCol] = Convert.ToChar(count.ToString());
            CheckRows(row, negCol);
        }
        else
        {
            break;
        }
        negCol--;
    } while (count == 0);
    
    do
    {
        posCol++;
        count = checkCellsAround(row, posCol);
        if(TryGetValue(row, posCol, out char value))
        {
            if (value != '-' && value != '0')
            {
                break;
            }
            board[row, posCol] = Convert.ToChar(count.ToString());
            CheckRows(row, posCol);
        }
        else
        {
            break;
        }
    } while (count == 0);
}

void CheckRows(int row, int col)
{
    int posRow = row;
    int negRow = row;
    int count;

    do
    {
        count = checkCellsAround(posRow, col);
        if(TryGetValue(posRow, col, out char value))
        {
            if (value != '-' && value != '0')
            {
                break;
            }
            board[posRow, col] = Convert.ToChar(count.ToString());
            posRow++;
        }
        else
        {
            break;
        }
        CheckColumns(posRow, col);
    } while (count == 0);
    
    do
    {
        count = checkCellsAround(negRow, col);
        if(TryGetValue(negRow, col, out char value))
        {
            if (value != '-' && value != '0')
            {
                break;
            }
            board[negRow, col] = Convert.ToChar(count.ToString());
            negRow--;
        }
        else
        {
            break;
        }
        CheckColumns(negRow, col);
    } while (count == 0);
}


int checkCellsAround(int row, int col)
{
    int count = 0;
    
    // Top row
    TryGetValue(row - 1, col - 1, out char value);
    if (value == '*') {count++;}
    TryGetValue(row - 1, col, out value);
    if (value == '*') {count++;}
    TryGetValue(row - 1, col + 1, out value);
    if (value == '*') {count++;}
    
    // Middle row
    TryGetValue(row, col - 1, out value);
    if (value == '*') {count++;}
    TryGetValue(row, col + 1, out value);
    if (value == '*') {count++;}
    
    // Bottom row
    TryGetValue(row + 1, col - 1, out value);
    if (value == '*') {count++;}
    TryGetValue(row + 1, col, out value);
    if (value == '*') {count++;}
    TryGetValue(row + 1, col + 1, out value);
    if (value == '*') {count++;}

    return count;
}


bool TryGetValue(int row, int col, out char value)
{
    try
    {
        value = board[row, col];
        return true;
    }
    catch (Exception e)
    {
        value = default;
        return false;
    }    
}


Console.WriteLine();
PrintBoard();
void PrintBoard()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (board[i,j] == '-' || board[i,j] == '*')
            {
                guess[i, j] = '#';
            }
            else
            {
                guess[i, j] = board[i, j];
            }
            Console.Write(guess[i,j]);
        }
        Console.WriteLine();
    }
}

char[,] PopulateBoard(char[,] board)
{
    Random random = new Random();

    int mineChance;
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            mineChance = random.Next(0, 7);
            if (mineChance == 1)
            {
                board[i, j] = '*';
            }
            else
            {
                board[i, j] = '-';
            }
        }   
    }
    return board;
}

void PrintBoardTest()
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Console.Write(board[i,j]);
        }
        Console.WriteLine();
    }
}