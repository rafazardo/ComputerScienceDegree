# Função responsável por inverter a tabela de ciclos
def inverterTabela(df, total_ciclos):
  # Inicia uma nova tabela
  global COD
  instr_list = []

  for i in range(len(COD)):
    instr_list.append(inst2text(COD[i]))
  tabela = {'programa': instr_list}

  instr_list = []
  for i in range(len(COD)):
    instr_list.append(" ")

  # Inicia o cabeçalho da tabela
  tabela["F"] = " "
  tabela["D"] = " "
  tabela["X"] = " "
  tabela["W"] = " "

  tempDf = pd.DataFrame(data=tabela) # Criar uma nova df temporaria com panda
  tempLine = 0 # Armazena a posição atual da linha

  for line in df.iloc: # Percorre por todas linhas (registradores) de df
    if (tempLine > len(COD) - 1):  # Se o numero da posicao da linha for maior que o numero de reg break
      break

    # Marca o inicio e fim de uma instrução
    inicioF = " "
    fimF = " "    
    teveF = False;

    inicioD = " "
    fimD = " "   
    teveD = False;

    inicioX = " "
    fimX = " "    
    teveX = False;  

    inicioW = " "
    fimW = " "    
    teveW = False;          

    for j in range(1,len(line)-1): # Percorre pelas instruções da linha
      if (line[j] == "F" and teveF != True):
        teveF = True;
        inicioF = str(j)
      if (line[j] == "F"):
        fimF = str(j)
      if (line[j] == "D" and teveD != True):
        teveD = True;
        inicioD = str(j)
      if (line[j] == "D"):
        fimD = str(j)     
      if (line[j] == "W"):
        teveW = True;
        inicioW = str(j)
        fimW = str(j)
      if (line[j] == "-"): 
        continue               
      if (line[j] != "F" and line[j] != "D" and line[j] != "W" and line[j] != " " and teveX != True):
        teveX = True;
        inicioX = str(j)
      if (line[j] != "F" and line[j] != "D" and line[j] != "W" and line[j] != " "):
        fimX = str(j)

      # Seta as intrucoes na nova tabela
      if (inicioF != fimF):
        tempDf.iloc[tempLine]["F"] = inicioF + "-" + fimF
      else: # Se for igual inicio e fim, nao precisamos de - 
        tempDf.iloc[tempLine]["F"] = inicioF 

      if (inicioD != fimD):
        tempDf.iloc[tempLine]["D"] = inicioD + "-" + fimD
      else: # Se for igual inicio e fim, nao precisamos de - 
        tempDf.iloc[tempLine]["D"] = inicioD  

      if (inicioX != fimX):
        tempDf.iloc[tempLine]["X"] = inicioX + "-" + fimX
      elif (inicioX == " " and fimX == " "): # Em casos de loop nao temos instrucao X, precisamos de -
        tempDf.iloc[tempLine]["X"] = "-"
      else: # Se for igual inicio e fim, nao precisamos de - 
        tempDf.iloc[tempLine]["X"] = inicioX   

      if (inicioW != fimW):
        tempDf.iloc[tempLine]["W"] = inicioW + "-" + fimW
      elif (inicioW == " " and fimW == " "): # Em casos de loop nao temos instrucao X, precisamos de -
        tempDf.iloc[tempLine]["W"] = "-"
      else: # Se for igual inicio e fim, nao precisamos de - 
        tempDf.iloc[tempLine]["W"] = inicioW                       

    tempLine = tempLine + 1

  return tempDf