@echo off
echo ========================================
echo  INSTALADOR Y EJECUTOR DE GRAFICOS
echo ========================================

echo 🔍 Verificando Python...
python --version >nul 2>&1
if %errorlevel% neq 0 (
    echo ❌ Python no esta instalado o no esta en el PATH
    echo 💡 Instala Python desde: https://www.python.org/downloads/
    echo    Asegurate de marcar "Add Python to PATH"
    pause
    exit /b 1
)

echo ✅ Python encontrado

echo.
echo 📦 Instalando dependencias necesarias...
echo.

echo Instalando pandas...
python -m pip install pandas

echo Instalando matplotlib...
python -m pip install matplotlib

echo Instalando numpy...
python -m pip install numpy

echo.
echo ✅ Dependencias instaladas

echo.
echo 🎯 Ejecutando análisis de datos...
echo.

python analizar_datos.py

echo.
echo ✅ Proceso completado
echo 📁 Revisa el archivo: analisis_metodos_numericos.png
echo.
pause
