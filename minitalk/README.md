<h2>MINITALK</h2>
<p>implementar un sistema de comunicación entre un servidor y un cliente utilizando señales Unix.</p>
<h2>Servidor</h2>
<ul>
    <li>Debe poder recibir señales del cliente.</li>
    <li>Cada señal representa un bit de información.</li>
    <li>El servidor debe manejar múltiples mensajes y finalizarlos correctamente.</li>
</ul>

<h2>Cliente</h2>
<ul>
    <li>Debe enviar mensajes al servidor utilizando señales.</li>
    <li>El cliente enviará cada carácter como una secuencia de señales (usualmente <code>SIGUSR1</code> para 0 y <code>SIGUSR2</code> para 1).</li>
</ul>

<h2>Instrucciones</h2>

<ol>
    <li><code>make</code></li>
    <li><code>./server</code></li>
    <li><code>./client &lt;nombre del servidor&gt; &lt;"cualquier mensaje que quieras escribir en cadenas"&gt;</code></li>
    <li>Pulsa <code>Control + Z</code> en tu teclado para cerrar el programa.</li>
</ol>
