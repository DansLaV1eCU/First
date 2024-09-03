import copy
import random

class Board:
    def __init__(self, code=None, solved_code = None): # Inicializace proměnné typu Board
        self.__resetBoard()

        if code: # Pokud je při vytváření třídy Board předán kód, vyplní se dvourozměrné pole
            self.code = code

            for row in range(9):
                for col in range(9):
                    self.board[row][col] = int(code[0])
                    code = code[1:]
        else:
            self.code = None

    def __resetBoard(self): # Vytvoří dvourozměrné pole představující sudoku. Nuly označují prázdná pole
        self.board = [
            [0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0],
        ]

        return self.board
    
    def boardToCode(self, input_board=None): # Přemění dvojité pole čísel na code (code je řetězec čísel vytvořený z čísel v řádcích dvojitého pole)
        if input_board:
            _code = ''.join([str(i) for j in input_board for i in j])
            return _code
        else:
            self.code = ''.join([str(i) for j in self.board for i in j]) # Pokud input_board je prázdný, tak vracíme self.code
            return self.code
        
    def findSpaces(self): # Najde první prázdné místo v sudoku, které je označeno číslem 0
        for row in range(len(self.board)):
            for col in range(len(self.board[0])):
                if self.board[row][col] == 0:
                    return (row, col)

        return False
    
    def checkSpace(self, num, space): # Zkontroluje, zda se číslo vejde do určitého prostoru; řádek, sloupec.
                                      # To znamená, že kontroluje, zda se číslo, které chceme vložit, nachází v daném sloupci, řádku a čtverci 3x3.
        if not self.board[space[0]][space[1]] == 0: # Zkontrolujte, zda je místo již číslem
            return False

        for col in self.board[space[0]]: # Zkontroluje, zda je číslo již v řádku
            if col == num:
                return False

        for row in range(len(self.board)): # Zkontroluje, zda je číslo již ve sloupci
            if self.board[row][space[1]] == num:
                return False

        _internalBoxRow = space[0] // 3
        _internalBoxCol = space[1] // 3

        for i in range(3): # Zkontroluje, zda interní pole 3x3 již má číslo
            for j in range(3):
                if self.board[i + (_internalBoxRow * 3)][j + (_internalBoxCol * 3)] == num:
                    return False
        
        return True

    def solve(self): # Řeší sudoku pomocí rekurze
        _spacesAvailable = self.findSpaces() # Hledáme volné pole

        if not _spacesAvailable: # Pokud v sudoku již nejsou žádná volná pole, program končí.
            return True
        else:
            row, col = _spacesAvailable

        for n in range(1, 10):
            if self.checkSpace(n, (row, col)): # Pokud je možné do tohoto pole vložit zadané číslo, spustíme rekurzi znovu
                self.board[row][col] = n
                
                if self.solve():
                    return self.board

                self.board[row][col] = 0

        return False
    
    def solveForCode(self): # Vyřeší sudoku a vrátí kód vyřešeného sudoku
        return self.boardToCode(self.solve())
    
    def __generateRandomCompleteBoard(self): # vygeneruje zcela novou zcela náhodnou sudoku plnou čísel
        self.__resetBoard()

        _l = list(range(1, 10)) # Nejprve vygeneruje levé horní pole 3x3
        for row in range(3):
            for col in range(3):
                _num = random.choice(_l)
                self.board[row][col] = _num
                _l.remove(_num)

        _l = list(range(1, 10)) # Pak středové pole 3x3
        for row in range(3, 6):
            for col in range(3, 6):
                _num = random.choice(_l)
                self.board[row][col] = _num
                _l.remove(_num)

        _l = list(range(1, 10)) # A nakonec pravé dolní pole 3x3
        for row in range(6, 9):
            for col in range(6, 9):
                _num = random.choice(_l)
                self.board[row][col] = _num
                _l.remove(_num)

        return self.__generateCont() # Poté se zavolá funkce, která vyplní všechna zbývající pole čísly
    
    def __generateCont(self): # Pomocí rekurze dokončí generování sudoku
        for row in range(len(self.board)):
            for col in range(len(self.board[row])):
                if self.board[row][col] == 0:
                    _num = random.randint(1, 9)

                    if self.checkSpace(_num, (row, col)): # Vyhledání prázdné buňky
                        self.board[row][col] = _num

                        if self.solve(): # Pokud je sudoka s daným číslem v daném pole řešitelná, provedeme novou rekurzi
                            self.__generateCont()
                            return self.board

                        self.board[row][col] = 0
        
        return False
    
    def __solveToFindNumberOfSolutions(self, row, col): # Řeší sudoku pomocí rekurze, používá se v rámci metody findNumberOfSolutions
        for n in range(1, 10):
            if self.checkSpace(n, (row, col)):
                self.board[row][col] = n

                if self.solve():
                    return self.board

                self.board[row][col] = 0

        return False
    
    def __findSpacesToFindNumberOfSolutions(self, board, h): # Najde první prázdné pole, na které narazí, používá se v metodě findNumberOfSolutions
        _k = 1
        for row in range(len(board)):
            for col in range(len(board[row])):
                if board[row][col] == 0:
                    if _k == h:
                        return (row, col)

                    _k += 1

        return False
    
    def findNumberOfSolutions(self): # Tato funkce je potřebná k určení počtu řešení konkrétního sudoku
        _z = 0
        _list_of_solutions = []

        for row in range(len(self.board)): # Počítání počtu zbývajících volných míst
            for col in range(len(self.board[row])):
                if self.board[row][col] == 0:
                    _z += 1

        for i in range(1, _z+1):
            _board_copy = copy.deepcopy(self)

            _row, _col = self.__findSpacesToFindNumberOfSolutions(_board_copy.board, i)
            _board_copy_solution = _board_copy.__solveToFindNumberOfSolutions(_row, _col)

            _list_of_solutions.append(self.boardToCode(input_board=_board_copy_solution))

        return list(set(_list_of_solutions)) # Vrátit množinu, nikoli seznam, aby se prvky neopakovaly
    
    def generateQuestionBoard(self, fullBoard, difficulty): # Tato funkce přijme jako parametr kompletně vyplněné sudoku a poté v závislosti na parametru obtížnosti odstraní čísla navíc
        self.board = copy.deepcopy(fullBoard)
        
        if difficulty == 0:
            _squares_to_remove = 36
        elif difficulty == 1:
            _squares_to_remove = 46
        elif difficulty == 2:
            _squares_to_remove = 52
        else:
            return
        
        _counter = 0
        while _counter < 4: # Nejprve vložíme nuly do levého horního pole
            _rRow = random.randint(0, 2)
            _rCol = random.randint(0, 2)
            if self.board[_rRow][_rCol] != 0:
                self.board[_rRow][_rCol] = 0
                _counter += 1

        _counter = 0
        while _counter < 4: # Pak do středu
            _rRow = random.randint(3, 5)
            _rCol = random.randint(3, 5)
            if self.board[_rRow][_rCol] != 0:
                self.board[_rRow][_rCol] = 0
                _counter += 1

        _counter = 0 # A nakonec do pravého dolního pole 3x3
        while _counter < 4:
            _rRow = random.randint(6, 8)
            _rCol = random.randint(6, 8)
            if self.board[_rRow][_rCol] != 0:
                self.board[_rRow][_rCol] = 0
                _counter += 1

        _squares_to_remove -= 12
        _counter = 0
        while _counter < _squares_to_remove: # Nyní odstraňme čísla ze ostatních polí
            _row = random.randint(0, 8)
            _col = random.randint(0, 8)

            if self.board[_row][_col] != 0:
                n = self.board[_row][_col]
                self.board[_row][_col] = 0

                if len(self.findNumberOfSolutions()) != 1: # Zkontrolujeme, zda má toto sudoku pouze 1 řešení (abychom ho mohli později zkontrolovat).
                    self.board[_row][_col] = n
                    continue

                _counter += 1

        return self.board, fullBoard # Funkce vrací hotové sudoku a jeho řešení
    
    def generateQuestionBoardCode(self, difficulty): # Generuje novou náhodnou sudoku a její code v závislosti na obtížnosti
        self.board, _solution_board = self.generateQuestionBoard(self.__generateRandomCompleteBoard(), difficulty)
        return self.boardToCode(), self.boardToCode(_solution_board)
    
    def printCodeAsMatrix(self, code): # Výstup sudoku do terminálu
        for i in range(len(code)):
            if ((i + 1) % 9 == 0):
                print(code[i])
            else:
                print(code[i], end=" ")

        return True
    
    def checkIfInputCorrect(self, code):
        
        if len(code) != 81: # Zkontrolujte, zda má vstupní řetězec přesně 81 znaků
            return False
        
        if not (code.isdigit()): # Pokud řetězec obsahue něco kromě čisel, tak False
            return False
        
        def has_no_duplicates(lst): # Pomocná funkce pro kontrolu, zda seznam obsahuje duplikáty, přičemž ignoruje nuly
            lst = [x for x in lst if x != '0']
            return len(lst) == len(set(lst))
        
        board = [list(code[i:i+9]) for i in range(0, 81, 9)]
        
        for row in board: # Kontrola řádků
            if not has_no_duplicates(row):
                return False
        
        for col in range(9): # Kontrola sloupců
            column = [board[row][col] for row in range(9)]
            if not has_no_duplicates(column):
                return False
        
        for box_row in range(0, 9, 3):  # Kontrola dílčích mřížek 3x3
            for box_col in range(0, 9, 3):
                box = []
                for row in range(box_row, box_row + 3):
                    for col in range(box_col, box_col + 3):
                        box.append(board[row][col])
                if not has_no_duplicates(box):
                    return False
        
        return True

        
board = Board() # Začátek hlavního programu. Inicializace proměnné třídy Board

print("Zvolte typ operace programu. 1 - řešení sudoku, 2 - generování sudoku") # Výběr úkolu pro program. Zapište do terminálu 1 pro řešení připraveného sudoku, 2 pro vytvoření sudoku zvolené složitosti a jeho řešení
_inp = input()

if (_inp == "1"):
    print("Vyberte typ vstupu. 1 - vstup přes terminál, 2 - vstup přes soubor") # Výběr způsobu zadávání sudoku, přes teranal nebo soubor
    _inp = input()

    if (_inp == "1"):
        code = input("Input sudoku code: ") # Do terminálu zadejte sudoku ve formátu „300105000060200000008090060050000800800007040071009035000900084704006000902048300“.

        if (board.checkIfInputCorrect(code)): # Zkontrolujme, zda je vstup správný
            if (Board(code).solveForCode() != code): # Zjistěme, zda existuje řešení
                board.code = Board(code).solveForCode() # Volání hlavní funkce pro řešení sudoku
                print("Řešením sudoku je")
                board.printCodeAsMatrix(board.code) # Výstup vyřešeného sudoku do terminálu
            else:
                print("Řešení neexistue")
        else:
            print("Nesprávný vstup")

    elif (_inp == "2"):
        f = open(input("Input file name: "), "r") # Zadejte název souboru, ve kterém je sudoku uloženo.
        code = f.readline()
        f.close

        if (board.checkIfInputCorrect(code)): # Zkontrolujme, zda je vstup správný
            if (Board(code).solveForCode() != code): # Zjistěme, zda existuje řešení
                board.code = Board(code).solveForCode() # Volání hlavní funkce pro řešení sudoku
                print("Řešením sudoku je")
                board.printCodeAsMatrix(board.code) # Výstup vyřešeného sudoku do terminálu
            else:
                print("Řešení neexistue")
        else:
            print("Nesprávný vstup")

    else:
        print("Nesprávný vstup")

elif (_inp == "2"):
    print("Zvolte obtížnost: 1 - snadná, 2 - střední, 3 - těžká") # Volba složitosti sudoku
    _inp = input()

    if (_inp == "1"):
        print("Připravte se, sudoku se vytváří")
        board.code, board.solved_code = board.generateQuestionBoardCode(0) # Generování snadné sudoku a řešení

        print("Sudoku snadné obtížnosti - vygenerováno")
        board.printCodeAsMatrix(board.code) # Výstup generováného sudoku do terminálu
    elif (_inp == "2"):
        print("Připravte se, sudoku se vytváří")
        board.code, board.solved_code = board.generateQuestionBoardCode(1) # Generování střední sudoku a řešení

        print("Sudoku střední obtížnosti - vygenerováno")
        board.printCodeAsMatrix(board.code) # Výstup generováného sudoku do terminálu
    elif (_inp == "3"):
        print("Připravte se, sudoku se vytváří")
        board.code, board.solved_code = board.generateQuestionBoardCode(2) # Generování těžké sudoku a řešení

        print("Sudoku těžké obtížnosti - vygenerováno")
        board.printCodeAsMatrix(board.code) # Výstup generováného sudoku do terminálu
    else:
        print("Nesprávný vstup")

    if (_inp == "1" or _inp == "2" or _inp == "3"):
        print("Chcete znát řešení? 1 - Ano, *Jakýkoli jiný vstup* - Ne") # Žádost o vypsání řešení vygenerovaného sudoku
        _inp = input()
        
        if (_inp == "1"):
            print("Řešení vygenerovaného sudoku je připraveno")
            board.printCodeAsMatrix(board.solved_code) # Výstup řešení generováného sudoku do terminálu

else:
    print("Nesprávný vstup")
