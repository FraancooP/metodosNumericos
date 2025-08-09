"""
Script simple para analizar datos sin dependencias externas
Solo usa librerías estándar de Python
"""
import csv
import math

def leer_csv_simple(nombre_archivo):
    """Lee un archivo CSV y devuelve los datos como listas"""
    try:
        with open(nombre_archivo, 'r') as archivo:
            lector = csv.DictReader(archivo)
            datos = list(lector)
            return datos
    except FileNotFoundError:
        print(f"⚠️  Archivo no encontrado: {nombre_archivo}")
        return []

def analizar_datos_simples():
    """Análisis básico de los datos sin gráficos"""
    print("🔍 ANÁLISIS DE DATOS DE MÉTODOS NUMÉRICOS")
    print("="*50)
    
    archivos = {
        'biseccion_raiz1.csv': 'Bisección - Raíz 1',
        'regla_falsi_raiz1.csv': 'Regla Falsi - Raíz 1',
        'biseccion_raiz2.csv': 'Bisección - Raíz 2',
        'regla_falsi_raiz2.csv': 'Regla Falsi - Raíz 2'
    }
    
    resultados = {}
    
    for archivo, nombre in archivos.items():
        datos = leer_csv_simple(archivo)
        if datos:
            resultados[nombre] = datos
            print(f"\n📊 {nombre}:")
            print(f"   • Iteraciones: {len(datos)}")
            if len(datos) > 0:
                ultimo = datos[-1]
                print(f"   • Error absoluto final: {ultimo['Error_Absoluto']}")
                print(f"   • Error de función final: {ultimo['Error_Funcion']}")
        else:
            print(f"\n❌ {nombre}: No se pudieron cargar los datos")
    
    if resultados:
        print("\n" + "="*50)
        print("📈 COMPARACIÓN DE CONVERGENCIA:")
        print("="*50)
        
        for nombre, datos in resultados.items():
            if 'Bisección' in nombre:
                if len(datos) <= 1:
                    print(f"🔸 {nombre}: Convergencia INSTANTÁNEA (0-1 iteraciones)")
                    print("   → Encontró la raíz exacta inmediatamente")
                else:
                    print(f"🔸 {nombre}: {len(datos)} iteraciones")
            else:  # Regla Falsi
                print(f"🔸 {nombre}: {len(datos)} iteraciones")
                if len(datos) > 100:
                    print("   → Convergencia LENTA pero estable")
                elif len(datos) > 10:
                    print("   → Convergencia MODERADA")
                else:
                    print("   → Convergencia RÁPIDA")
        
        print("\n" + "="*50)
        print("🎯 CONCLUSIONES:")
        print("="*50)
        print("• La función g(x) = x¹⁰ - 1 tiene raíces exactas en x = -1 y x = 1")
        print("• Los intervalos elegidos hacen que Bisección caiga exactamente en las raíces")
        print("• Regla Falsi usa interpolación lineal y necesita converger gradualmente")
        print("• Ambos métodos encuentran las raíces correctas, solo difieren en velocidad")
        
    else:
        print("\n❌ No se encontraron datos para analizar")
        print("💡 Ejecuta primero el programa C++ para generar los archivos CSV")

def crear_datos_ejemplo():
    """Crea archivos de ejemplo si no existen"""
    print("\n🔧 Creando archivos de ejemplo...")
    
    # Bisección - encuentra raíz inmediatamente
    with open('ejemplo_biseccion.csv', 'w', newline='') as f:
        escritor = csv.writer(f)
        escritor.writerow(['Iteracion', 'Error_Absoluto', 'Error_Relativo', 'Error_Funcion'])
        escritor.writerow([0, 0.0, 0.0, 0.0])
    
    # Regla Falsi - convergencia gradual
    with open('ejemplo_regla_falsi.csv', 'w', newline='') as f:
        escritor = csv.writer(f)
        escritor.writerow(['Iteracion', 'Error_Absoluto', 'Error_Relativo', 'Error_Funcion'])
        for i in range(160):
            error_abs = 1.0 * (0.95 ** i)  # Convergencia exponencial
            error_rel = error_abs / 1.0
            error_func = error_abs ** 10
            escritor.writerow([i, error_abs, error_rel, error_func])
    
    print("✅ Archivos de ejemplo creados:")
    print("   • ejemplo_biseccion.csv")
    print("   • ejemplo_regla_falsi.csv")

if __name__ == "__main__":
    print("🎯 ANALIZADOR SIMPLE DE MÉTODOS NUMÉRICOS")
    print("🔧 No requiere librerías externas")
    print("")
    
    analizar_datos_simples()
    
    respuesta = input("\n¿Crear archivos de ejemplo? (s/n): ").lower()
    if respuesta in ['s', 'si', 'sí', 'y', 'yes']:
        crear_datos_ejemplo()
    
    print("\n✅ Análisis completado")
    input("Presiona Enter para salir...")
