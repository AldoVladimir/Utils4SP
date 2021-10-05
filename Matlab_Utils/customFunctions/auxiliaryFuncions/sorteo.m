function sorteo(n)
%% lectura de datos
data=readtable('~/Escritorio/ProcSeñales/customFunctions/auxiliaryFuncions/dataBase.xlsx');

%% Sorteo
index=min(data.Part)==data.Part;
numbers=data.No(index);
numbers=numbers(randperm(numel(numbers),min([n numel(numbers)])));
index= index & ismember(data.No,numbers);
disp(data.Nombre(index))

%% Cuenta de participacion y escritura
data.Part(index)=data.Part(index)+1;
writetable(data,'~/Escritorio/ProcSeñales/customFunctions/auxiliaryFuncions/dataBase.xlsx')

end