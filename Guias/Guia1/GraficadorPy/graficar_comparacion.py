import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import os

def graficar_comparacion_metodos():
    """
    Función para crear gráficos comparativos de los métodos numéricos
    """
    print("🔍 Buscando archivos CSV...")
    
    # Lista de archivos esperados
    archivos = {
        'biseccion_raiz1.csv': 'Bisección - Raíz 1 ([-1.5, -0.5])',
        'regla_falsi_raiz1.csv': 'Regla Falsi - Raíz 1 ([-1.5, -0.5])',
        'biseccion_raiz2.csv': 'Bisección - Raíz 2 ([0.5, 1.5])',
        'regla_falsi_raiz2.csv': 'Regla Falsi - Raíz 2 ([0.5, 1.5])'
    }
    
    datos = {}
    
    # Cargar datos de los archivos CSV
    for archivo, etiqueta in archivos.items():
        if os.path.exists(archivo):
            try:
                df = pd.read_csv(archivo)
                datos[etiqueta] = df
                print(f"✓ Cargado: {archivo} ({len(df)} iteraciones)")
            except Exception as e:
                print(f"❌ Error al cargar {archivo}: {e}")
        else:
            print(f"⚠️  Archivo no encontrado: {archivo}")
    
    if not datos:
        print("❌ No se encontraron archivos CSV. Ejecuta primero el programa C++.")
        return
    
    # Crear figura con subgráficos
    fig, axes = plt.subplots(2, 2, figsize=(15, 12))
    fig.suptitle('Comparación de Métodos Numéricos: g(x) = x^10 - 1', fontsize=16, fontweight='bold')
    
    # Colores para cada método
    colores = {
        'Bisección': '#1f77b4',  # Azul
        'Regla Falsi': '#ff7f0e'  # Naranja
    }
    
    # Gráfico 1: Error Absoluto vs Iteraciones
    ax1 = axes[0, 0]
    for etiqueta, df in datos.items():
        metodo = 'Bisección' if 'Bisección' in etiqueta else 'Regla Falsi'
        color = colores[metodo]
        estilo = '-o' if 'Bisección' in etiqueta else '-s'
        ax1.semilogy(df['Iteracion'], df['Error_Absoluto'], estilo, 
                    color=color, label=etiqueta, markersize=4, linewidth=2)
    
    ax1.set_xlabel('Número de Iteraciones')
    ax1.set_ylabel('Error Absoluto (escala log)')
    ax1.set_title('Error Absoluto vs Iteraciones')
    ax1.legend(fontsize=9)
    ax1.grid(True, alpha=0.3)
    
    # Gráfico 2: Error Relativo vs Iteraciones
    ax2 = axes[0, 1]
    for etiqueta, df in datos.items():
        metodo = 'Bisección' if 'Bisección' in etiqueta else 'Regla Falsi'
        color = colores[metodo]
        estilo = '-o' if 'Bisección' in etiqueta else '-s'
        # Filtrar valores cero para la escala logarítmica
        mask = df['Error_Relativo'] > 0
        if mask.any():
            ax2.semilogy(df.loc[mask, 'Iteracion'], df.loc[mask, 'Error_Relativo'], 
                        estilo, color=color, label=etiqueta, markersize=4, linewidth=2)
    
    ax2.set_xlabel('Número de Iteraciones')
    ax2.set_ylabel('Error Relativo (escala log)')
    ax2.set_title('Error Relativo vs Iteraciones')
    ax2.legend(fontsize=9)
    ax2.grid(True, alpha=0.3)
    
    # Gráfico 3: Error de la Función vs Iteraciones
    ax3 = axes[1, 0]
    for etiqueta, df in datos.items():
        metodo = 'Bisección' if 'Bisección' in etiqueta else 'Regla Falsi'
        color = colores[metodo]
        estilo = '-o' if 'Bisección' in etiqueta else '-s'
        mask = df['Error_Funcion'] > 0
        if mask.any():
            ax3.semilogy(df.loc[mask, 'Iteracion'], df.loc[mask, 'Error_Funcion'], 
                        estilo, color=color, label=etiqueta, markersize=4, linewidth=2)
    
    ax3.set_xlabel('Número de Iteraciones')
    ax3.set_ylabel('|f(x)| (escala log)')
    ax3.set_title('Valor Absoluto de la Función vs Iteraciones')
    ax3.legend(fontsize=9)
    ax3.grid(True, alpha=0.3)
    
    # Gráfico 4: Comparación de Convergencia (solo métodos que convergen)
    ax4 = axes[1, 1]
    for etiqueta, df in datos.items():
        if len(df) > 1:  # Solo si hay más de una iteración
            metodo = 'Bisección' if 'Bisección' in etiqueta else 'Regla Falsi'
            color = colores[metodo]
            estilo = '-o' if 'Bisección' in etiqueta else '-s'
            ax4.plot(df['Iteracion'], df['Error_Absoluto'], estilo, 
                    color=color, label=etiqueta, markersize=4, linewidth=2)
    
    ax4.set_xlabel('Número de Iteraciones')
    ax4.set_ylabel('Error Absoluto')
    ax4.set_title('Convergencia - Escala Lineal')
    ax4.legend(fontsize=9)
    ax4.grid(True, alpha=0.3)
    
    plt.tight_layout()
    
    # Guardar gráfico
    plt.savefig('comparacion_metodos_numericos.png', dpi=300, bbox_inches='tight')
    print("\n✓ Gráfico guardado como: comparacion_metodos_numericos.png")
    
    # Mostrar estadísticas
    print("\n📊 ESTADÍSTICAS:")
    print("="*50)
    for etiqueta, df in datos.items():
        print(f"\n{etiqueta}:")
        print(f"  • Iteraciones: {len(df)}")
        if len(df) > 0:
            print(f"  • Error final absoluto: {df['Error_Absoluto'].iloc[-1]:.2e}")
            print(f"  • Error final función: {df['Error_Funcion'].iloc[-1]:.2e}")
    
    # Mostrar gráfico
    plt.show()

def crear_grafico_comparativo_simple():
    """
    Versión simplificada para casos específicos
    """
    print("📈 Creando gráfico comparativo simplificado...")
    
    # Datos de ejemplo si no hay archivos
    if not any(os.path.exists(f) for f in ['biseccion_raiz1.csv', 'regla_falsi_raiz1.csv']):
        print("⚠️  No se encontraron archivos CSV. Creando ejemplo teórico...")
        
        # Simular datos para bisección (convergencia rápida)
        iter_biseccion = [0]
        error_biseccion = [0.0]  # Encuentra la raíz inmediatamente
        
        # Simular datos para regla falsi (convergencia gradual)
        iter_regla_falsi = list(range(0, 160))
        error_regla_falsi = [1.0 * (0.9 ** i) for i in iter_regla_falsi]
        
        plt.figure(figsize=(12, 8))
        
        plt.subplot(2, 1, 1)
        plt.semilogy(iter_biseccion, [1e-15], 'bo-', label='Bisección', markersize=8)
        plt.semilogy(iter_regla_falsi, error_regla_falsi, 'rs-', label='Regla Falsi', markersize=4)
        plt.xlabel('Iteraciones')
        plt.ylabel('Error (escala log)')
        plt.title('Comparación de Convergencia: g(x) = x^10 - 1')
        plt.legend()
        plt.grid(True, alpha=0.3)
        
        plt.subplot(2, 1, 2)
        plt.plot(iter_regla_falsi, error_regla_falsi, 'rs-', label='Regla Falsi', markersize=4)
        plt.axhline(y=0, color='b', linestyle='-', linewidth=3, label='Bisección (encuentra raíz exacta)')
        plt.xlabel('Iteraciones')
        plt.ylabel('Error (escala lineal)')
        plt.title('Convergencia - Vista Detallada')
        plt.legend()
        plt.grid(True, alpha=0.3)
        
        plt.tight_layout()
        plt.savefig('ejemplo_convergencia.png', dpi=300, bbox_inches='tight')
        plt.show()
        
        print("✓ Gráfico de ejemplo creado: ejemplo_convergencia.png")

if __name__ == "__main__":
    print("🎯 Generador de Gráficos Comparativos - Métodos Numéricos")
    print("="*60)
    
    try:
        graficar_comparacion_metodos()
    except Exception as e:
        print(f"❌ Error en gráfico principal: {e}")
        print("🔄 Intentando con gráfico simplificado...")
        crear_grafico_comparativo_simple()
    
    print("\n✅ Proceso completado!")
