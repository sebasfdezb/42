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
<img src="https://raw.githubusercontent.com/sebasfdezb/42/main/minitalk/DALL%C2%B7E%202024-10-10%2013.07.54%20-%20An%20illustration%20representing%20the%20'Minitalk'%20project%20from%2042%2C%20showcasing%20a%20creative%20concept%20of%20two%20computers%20communicating%20through%20a%20series%20of%20colorful.webp" alt="Minitalk project illustration" width="300px">
