program labEmployeeSalary;

uses
  System.StartUpCopy,
  FMX.Forms,
  fmu in 'fmu.pas' {Form1},
  dmu in 'dmu.pas' {DataModule2: TDataModule};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.CreateForm(TDataModule2, DataModule2);
  Application.Run;
end.
